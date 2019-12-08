/*
 * input.c
 * 
 * 
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


#include "gpr.h"
#include "gpr_allocator.h"
#include "gpr_buffer.h"
#include "buffer.h"
#include "vc5_encoder.h"
#include "timer.h"
#include "config.h"

#include "cluster.h"
#include "input.h"

#define INPUT_PIPE "/tmp/pipe"

#define PIPE_CAM   "/tmp/cpipe"

void print_buffer_status(buf_handle_t buf);

static struct dirent **_list;
static int    _len, _idx = 0;
static char *_dirname;

static bool use_cam;
static int cfd;

static int _filter(const struct dirent *d)
{
	return d->d_name[0] != '.';
}

int init_input(struct cluster_args *args, buf_handle_t *buf)
{
	use_cam = args->use_cam;
	if(use_cam){
		int pid = fork();
		if(pid == 0){
			execlp(args->cam_path, args->cam_path, PIPE_CAM, "./CDNG", NULL);
			fprintf(stderr, "Failed to exec camera: %s\n", args->cam_path);
			exit(1);
		}
		mkfifo(PIPE_CAM, 0666);
		cfd = open(PIPE_CAM, O_RDONLY);
		return 0;
	}
	_dirname = args->in_dir;
	_len = scandir(args->in_dir, &_list, _filter, versionsort);
	if(_len != -1){
		return 0;
	}else{
		fprintf(stderr, "Could not open dir: %s\n", args->in_dir);
		exit(-1);
	}
}

static int _fnum = 0;


void _get_img_buf(void *buf, int sz, void **frame, struct raw_prefix **pout)
{
	//Allocate a buffer to read this shiz into
	gpr_allocator allocator;
	//for now use malloc, eventually use buffer allocators
	allocator.Alloc = malloc;
	allocator.Free = free;

	//Struct for image parameters
	*pout = malloc(sizeof(struct raw_prefix));
	gpr_parameters_set_defaults(&(*pout)->params);
	gpr_buffer input_buffer = {buf, sz};

	gpr_parse_metadata( &allocator, &input_buffer, &(*pout)->params);
	(*pout)->framenum = _fnum++;
	(*pout)->size = input_buffer.size;
	*frame = input_buffer.buffer;

}

void _get_raw_image(char *path, void **frame, struct raw_prefix **pout)
{

	//Allocate a buffer to read this shiz into
	gpr_allocator allocator;
	//for now use malloc, eventually use buffer allocators
	allocator.Alloc = malloc;
	allocator.Free = free;

	//Struct for image parameters
	*pout = malloc(sizeof(struct raw_prefix));
	gpr_parameters_set_defaults(&(*pout)->params);

	//create gpr_buffer struct
	gpr_buffer input_buffer  = { NULL, 0 };

	//Use routine in gpr libraries to make this easy
	if( read_from_file( &input_buffer, path, allocator.Alloc, allocator.Free ) != 0 )
	{
		*frame = NULL;
		*pout = NULL;
	}

	//Now we have an image open, read parameters into struct
	gpr_parse_metadata( &allocator, &input_buffer, &(*pout)->params);
	(*pout)->framenum = _fnum++;
	(*pout)->size = input_buffer.size;
	*frame = input_buffer.buffer;
}

int get_frame(void **frame, struct raw_prefix **params)
{
	if(use_cam){
		char *f;
		int sz;
		int rd = 0;
		if(read(cfd, &sz, sizeof(int)) != 4){
			exit(-1);	
		}
		printf("Reading %d bytes\n", sz);
		if(sz == -1){
			*frame = NULL;
			*params = NULL;
			return 1;
		}
		f = malloc(sz * sizeof(char));
		while(rd != sz){
			rd += read(cfd, f + rd, (sz - rd));
		}
		_get_img_buf(f, sz, frame, params);
		return 0;
	}
	struct dirent *ent;
	if(_idx < _len){
		ent = _list[_idx++];
		char *fullpath = malloc(strlen(_dirname) 
				+ strlen(ent->d_name) + 2);
		if (fullpath == NULL) { 
			exit(5);
			/* Uh We Might be F****d here? Whatever */ }
		sprintf(fullpath, "%s/%s", _dirname, ent->d_name);
		VLOGF("Reading file: %s\n", fullpath);
		_get_raw_image(fullpath, frame, params);
		free(fullpath);
	}else{
		VLOGF("End of input\n");
		return 1;
	}
	return 0;
}

void print_buffer_status(buf_handle_t buf)
{
	printf("Full: %d, empty: %d, size: %zu\n",
		buf_full(buf),
		buf_empty(buf),
		buf_size(buf));
}


