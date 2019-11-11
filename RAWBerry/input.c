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

#include "timer.h"
#include "config.h"

#include "input.h"
#include "gpr_buffer.h"


#define EXAMPLE_BUFFER_SIZE 10
#define INPUT_WIDTH 1952
#define INPUT_HEIGHT 1112
#define INPUT_PIPE "/tmp/pipe"
#define BUFF_SIZE 400000000

static DIR *_dir;

static char *_dirname;


static int _fnum = 0;
int init_input(struct cluster_args *args)
{
	
	_dirname = "./CDNG"; //do something later
	//define and allocate memory for input-buffer
	
	if(_dir = opendir(_dirname)) {
		return 0;
	}else{
		//abort
		exit(-1);
	}
}


void _get_raw_image(char *path, gpr_buffer *frame)
{
    //Allocate a buffer to read this shiz into
	gpr_allocator allocator;
	//for now use malloc, eventually use buffer allocators
	allocator.Alloc = malloc;
	allocator.Free = free;

	//Use routine in gpr libraries to make this easy
	if( read_from_file( &frame, path, allocator.Alloc, allocator.Free ) != 0 )
	{
	    return NULL;
	}
	
}


int get_frame(gpr_buffer * frame)
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
		_get_raw_image(fullpath, frame);
		free(fullpath);
	}else{
		fprintf(stderr, "could not read");
		return 1;
	}
	return 0;
}





