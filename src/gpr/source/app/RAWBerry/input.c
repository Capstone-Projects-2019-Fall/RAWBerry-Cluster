/*
 * input.c
 * 
 * 
 */


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

#define EXAMPLE_BUFFER_SIZE 10
#define INPUT_WIDTH 1952
#define INPUT_HEIGHT 1112
#define INPUT_PIPE "/tmp/pipe"
#define BUFF_SIZE 400000000

void print_buffer_status(buf_handle_t buf);

static DIR *_dir;
static char *_dirname;

int init_input(struct cluster_args *args, buf_handle_t *buf)
{
	_dirname = args->in_dir; //do something later
	if(_dir = opendir(_dirname)) {
		return 0;
	}else{
		//abort
		exit(-1);
	}
}

static int _fnum = 0;

void _get_raw_image(char *path, void **frame, void **pout)
{

	//Allocate a buffer to read this shiz into
	gpr_allocator allocator;
	//for now use malloc, eventually use buffer allocators
	allocator.Alloc = malloc;
	allocator.Free = free;

	//Struct for image parameters
	gpr_parameters params;
	gpr_parameters_set_defaults(&params);

	//create gpr_buffer struct
	gpr_buffer input_buffer  = { NULL, 0 };

	//Use routine in gpr libraries to make this easy
	if( read_from_file( &input_buffer, path, allocator.Alloc, allocator.Free ) != 0 )
	{
		*frame = NULL;
		*pout = NULL;
	}

	//Now we have an image open, read parameters into struct
	gpr_parse_metadata( &allocator, &input_buffer, &params );
	params.preview_image.preview_height = _fnum++; //cheap hack
	params.preview_image.preview_width = input_buffer.size;
	*pout = malloc(sizeof(gpr_parameters));
	memcpy(*pout, &params, sizeof(gpr_parameters));
	*frame = input_buffer.buffer;
}

int get_frame(void **frame, void **params)
{
	struct dirent *ent;
start:	if((ent = readdir(_dir))) {
		if(*(ent->d_name) == '.'){
			goto start;
		}
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


