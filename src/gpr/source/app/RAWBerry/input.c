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

#define EXAMPLE_BUFFER_SIZE 10
#define INPUT_WIDTH 1952
#define INPUT_HEIGHT 1112
#define INPUT_PIPE "/tmp/pipe"
#define BUFF_SIZE 400000000

int fd;


int readFiles(char* directory, buf_handle_t buf);
int openImage(char* filePath, buf_handle_t buf);
void print_buffer_status(buf_handle_t buf);
int encodeImage(gpr_buffer * output_buffer, vc5_encoder_parameters * vc5_encoder_params, gpr_buffer * vc5_image);
void _coll_stream_frame(void *frame, int sz);


int readFiles(char* directory, buf_handle_t buf){
	
DIR *dir;
struct dirent **ent;
int i,n;

    printf("Opening Pipe\n");
    mkfifo(INPUT_PIPE, 0666);
    fd = open(INPUT_PIPE, O_WRONLY);
   printf("Pipe Open");


 n = scandir(directory, &ent, 0, alphasort);
    if (n < 0)
        perror("scandir");
    else {
        for (i = 0; i < n; i++) {
             if(strcmp(ent[i]->d_name, ".") == 0 || strcmp(ent[i]->d_name, "..") == 0)
                continue;
            char *fullpath = malloc(strlen(directory)+ strlen(ent[i]->d_name) + 2);
            if (fullpath == NULL) { /* Uh We Might be F****d here? Whatever */  return -1; }
            sprintf(fullpath, "%s/%s", directory, ent[i]->d_name);
            printf("%s\n", ent[i]->d_name);

            openImage(fullpath, buf);
            /* use fullpath */
            free(fullpath);
            free(ent[i]);
        }
  
    closedir (dir);
  	unlink(INPUT_PIPE);
} 

	return 0;
}

int openImage(char* filePath, buf_handle_t buf){
	gpr_allocator allocator;
    allocator.Alloc = malloc;
    allocator.Free = free;
    
    gpr_parameters params;
    gpr_parameters_set_defaults(&params);
    params.tuning_info.pixel_format = PIXEL_FORMAT_GBRG_12;
    
    gpr_buffer input_buffer  = { NULL, 0 };
    gpr_buffer output_buffer = { NULL, 0 };
    
    if( read_from_file( &input_buffer, filePath, allocator.Alloc, allocator.Free ) != 0 )
    {
        return -1;
    }
  
    

    printf("Read:%d Bytes\n", input_buffer.size);
	
    gpr_parse_metadata( &allocator, &input_buffer, &params );

    gpr_rgb_buffer rgb_buffer = { NULL, 0, 0, 0 };
    GPR_RGB_RESOLUTION rgb_resolution = GPR_RGB_RESOLUTION_HALF;
    
    
    int rgb_file_bits = 16;
    
    int success = gpr_convert_dng_to_gpr( &allocator, &params, &input_buffer, &output_buffer );
    
    _coll_stream_frame(output_buffer.buffer, output_buffer.size);
    //Temp Write out file for giggles
    char* output_file_path = filePath;
    int len = strlen(filePath);
    output_file_path[(len - 3)] = 'G';
    output_file_path[(len - 2)] = 'P';
    output_file_path[(len - 1)] = 'R';

  if( write_to_file( &output_buffer, output_file_path ) )
        {
            LogPrint("Error writing bitstream to location %s",  output_file_path);
            return -1;
        }
    printf("Wrote %d Bytes\n",rgb_buffer.size);
  
    return 0;
}

int encodeImage(gpr_buffer * output_buffer, vc5_encoder_parameters * vc5_encoder_params, gpr_buffer * vc5_image){
	TIMER timer;
    	InitTimer(&timer);
	
	StartTimer(&timer);
        vc5_encoder_process( vc5_encoder_params, output_buffer, vc5_image, NULL );
        StopTimer(&timer);
        assert( vc5_image->buffer && vc5_image->size > 0 );
	return TimeSecs(&timer);

}

void _coll_stream_frame(void *frame, int sz)
{
    //used to track bytes written to pipe
    int bytes_written = 0;

    //open pipe
    int pipe_fd = open("/tmp/pipe", O_WRONLY);
    //write size of frame to pipe
    write(pipe_fd, &sz, sizeof(int));

    //write frame to pipe piece-wise
    while (bytes_written != sz){
        //puts("Write");
        bytes_written += write(pipe_fd, frame, (sz - bytes_written));
    }
    close(pipe_fd);
    printf("Wrote: %d Bytes\n", bytes_written);
    printf("%s: %d\n", ((char*)frame)+4, *(int*)frame);
}



void print_buffer_status(buf_handle_t buf)
{
	printf("Full: %d, empty: %d, size: %zu\n",
		buf_full(buf),
		buf_empty(buf),
		buf_size(buf));
}


