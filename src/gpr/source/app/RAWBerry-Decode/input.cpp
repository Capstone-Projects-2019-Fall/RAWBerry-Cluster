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
#include <argp.h>

#include <opencv2/core/core_c.h>
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2/highgui/highgui_c.h>


#include "gpr.h"
#include "gpr_allocator.h"
#include "gpr_buffer.h"
#include "vc5_decoder.h"
#include "timer.h"
#include "config.h"
#include "gpr_parse_utils.h"


#define EXAMPLE_BUFFER_SIZE 10
#define INPUT_WIDTH 1952
#define INPUT_HEIGHT 1112
#define INPUT_PIPE "/tmp/pipe"
#define BUFF_SIZE 400000000

#define TMP_FILE "/tmp/decode_tmp.ppm"

#define IN_PIPE "/tmp/ipipe"
int fd;


int readFiles(char* directory);
char *openImage(char* filePath);

static int _use_tmpfile = 1;
static char *_input_dir = "./input";
static int no_pipe = 0;

static char *doc = "RAWBerry-Decode -- a compressed file viewer";
static char *args_doc = "<OPTIONS>";
static struct argp_option options[] = {
	{"no-tempfile", 'n', 0, 0, "Do not use a tempfile, write out uncompressed images"},
	{"input-dir", 'i', "DIR", 0, "Directory to read files from"},
	{"no-pipe", 'p', 0, 0, "Do not use pipe"}, 
	{ 0 },
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	switch(key){
		case 'n': _use_tmpfile = 0;
			  break;
		case 'i': _input_dir = arg;
			  break;
		case 'p': no_pipe = 1;
			  break;
		case ARGP_KEY_END:
			  break;
		default:
			  return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc };

int main(int argc, char **argv)
{
	argp_parse(&argp, argc, argv, 0, 0, NULL);
	int status = readFiles(_input_dir);
	return status;
}

void read_file(char *directory, char *name)
{
	CvMat * image;
	char *fullpath = no_pipe ? (char *) malloc(strlen(directory)+ strlen(name) + 2) : NULL;
	if(no_pipe){
		if (fullpath == NULL) { exit(-5); }
		sprintf(fullpath, "%s/%s", directory, name);
	}
	char *read  = openImage(fullpath);
	if(read){
		printf("Reading: %s\n", read);
		image = cvLoadImageM(read, CV_LOAD_IMAGE_COLOR);
		cvShowImage( "Display window", image );            
		cvWaitKey(42); 
	}
	if(no_pipe)
		free(fullpath);
}

static int _filter(const struct dirent *d)
{
	return *d->d_name != '.';
}

int readFiles(char* directory)
{
	if(!no_pipe){
		cvNamedWindow( "Display window", CV_WINDOW_AUTOSIZE ); 
		mkfifo(IN_PIPE, 0666);
		fd = open(IN_PIPE, O_RDONLY);
		while(1){
			read_file(directory, "null");
		}
	}else{
		DIR *dir;
		struct dirent *ent;
		cvNamedWindow( "Display window", CV_WINDOW_AUTOSIZE ); 
		struct dirent **list;
		int len, i = 0;
		len = scandir(directory, &list, _filter, versionsort);
		if (len != -1){
			for(; i < len; i++){
				read_file(directory, list[i]->d_name);
			} 
			free(list);
		}else{
			/* could not open directory */
			perror ("");
			return EXIT_FAILURE;
		}
	}
	return 0;
}

char *openImage(char * filePath)
{
    
	gpr_allocator allocator;
	allocator.Alloc = malloc;
	allocator.Free = free;

	gpr_parameters params;
	gpr_parameters_set_defaults(&params);

	gpr_buffer output_buffer = { NULL, 0 };
	gpr_buffer input_buffer  = { NULL, 0 };
	if(no_pipe){
		printf("Reading: %s\n", filePath);
		if( read_from_file( &input_buffer, filePath, allocator.Alloc, allocator.Free ) != 0 )
		{
			return 0;
		}
	}else{
		int rd = 0;
		int sz = 0;
		if(read(fd, &sz, sizeof(int)) != 4){
			exit(-1);	
		}
		if(sz == -1){
			exit(-2);
		}
		char *f = (char *) malloc(sz * sizeof(char));
		while(rd != sz){
			rd += read(fd, f + rd, (sz - rd));
		}
		input_buffer.buffer = f;
		input_buffer.size = sz;
	}

	printf("Read:%d Bytes\n", input_buffer.size);
	    
	gpr_parse_metadata( &allocator, &input_buffer, &params );
	gpr_rgb_buffer rgb_buffer = { NULL, 0, 0, 0 };
	GPR_RGB_RESOLUTION rgb_resolution = GPR_RGB_RESOLUTION_HALF;

	int rgb_file_bits = 8;
	int success = gpr_convert_gpr_to_rgb( &allocator, rgb_resolution, rgb_file_bits,  &input_buffer, &rgb_buffer );

	char header_text[100];

	sprintf( header_text, "P6\n%ld %ld\n255\n", rgb_buffer.width, rgb_buffer.height );
		
	output_buffer.size   = rgb_buffer.size + strlen( header_text );
	output_buffer.buffer = allocator.Alloc( output_buffer.size );
	char* buffer_c = (char*)output_buffer.buffer;
		
	memcpy( buffer_c, header_text, strlen( header_text ) );
	memcpy( buffer_c + strlen( header_text ), rgb_buffer.buffer, rgb_buffer.size );

	char* output_file_path = TMP_FILE;
	if(!_use_tmpfile){
		output_file_path = filePath;
		int len = strlen(filePath);
		output_file_path[(len - 3)] = 'p';
		output_file_path[(len - 2)] = 'p';
		output_file_path[(len - 1)] = 'm';
	}
	if(write_to_file(&output_buffer, output_file_path)){
        	printf("Error writing bitstream to location %s",  output_file_path);
        	return 0;
        }
   	printf("Wrote %d Bytes\n",rgb_buffer.size);
    	return output_file_path;
}

