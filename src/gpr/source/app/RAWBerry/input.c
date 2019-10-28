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

/*int main(int argc, char **argv)
{
    
    gpr_buffer * buffer  = malloc(EXAMPLE_BUFFER_SIZE * sizeof(gpr_buffer));
    
    printf("\n=== Buffer Check ===\n");

    buf_handle_t buf = buf_init(buffer, EXAMPLE_BUFFER_SIZE);

    printf("Buffer initialized. ");
    print_buffer_status(buf);
    
    char dir[] = "/home/pi/Documents/CDNG";
    int status = readFiles(dir, buf);
    
    free(buffer);
    return status;
	}*/

int readFiles(char* directory, buf_handle_t buf){
	
DIR *dir;
struct dirent *ent;

    printf("Opening Pipe\n");
    mkfifo(INPUT_PIPE, 0666);
    fd = open(INPUT_PIPE, O_WRONLY);
    printf("Pipe Open");
//char dir[] = "/CDNG/Blackmagic Pocket Cinema Camera_1_2014-08-13_1850_C0002_000000.dng";
//openImage(dir, buf);
if ((dir = opendir (directory)) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL && (buf_full(buf) == false)) {
    
    //Get us a string with the full path so we can open file
	char *fullpath = malloc(strlen(directory)+ strlen(ent->d_name) + 2);
	if (fullpath == NULL) { /* Uh We Might be F****d here? Whatever */ }
	sprintf(fullpath, "%s/%s", directory, ent->d_name);
	openImage(fullpath, buf);
	/* use fullpath */
	free(fullpath);
	//print_buffer_status(buf);
    //Do Things with files
    
}
  
 closedir (dir);
  	unlink(INPUT_PIPE);
} else {
  /* could not open directory */
  perror ("");
 return EXIT_FAILURE;
}
	return 0;
}

int openImage(char* filePath, buf_handle_t buf){
	
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
    if( read_from_file( &input_buffer, filePath, allocator.Alloc, allocator.Free ) != 0 )
    {
        return -1;
    }
    
    //Now we have an image open, read parameters into struct
    gpr_parse_metadata( &allocator, &input_buffer, &params );
    
    //This should be in the circular buffer
    gpr_buffer output_buffer = { NULL, 0 };
    
    
    //int success = gpr_convert_dng_to_gpr( &allocator, &params, &input_buffer, &output_buffer );
    
    int success = gpr_convert_dng_to_raw( &allocator, &input_buffer, &output_buffer );
    printf ("%s\n", filePath);
    gpr_parameters_destroy(&params, allocator.Free);
	
    if( success == 0 )
    {
        printf("Conversion failed \n");
        return -1;
    }
    //buf_put(buf, &output_buffer);

    gpr_buffer vc5_image = { NULL, 0  };
	
   vc5_encoder_parameters vc5_encoder_params;
    vc5_encoder_parameters_set_default(&vc5_encoder_params);
    vc5_encoder_params.enabled_parts    = VC5_ENABLED_PARTS;
   vc5_encoder_params.input_width      = INPUT_WIDTH;
    vc5_encoder_params.input_height     = INPUT_HEIGHT;
    vc5_encoder_params.input_pitch      = INPUT_WIDTH * 2;
    vc5_encoder_params.mem_alloc        = malloc;
    vc5_encoder_params.mem_free         = free;

    encodeImage(&output_buffer, &vc5_encoder_params, &vc5_image);
    //LogPrint("Encoding %.3f secs per frame", encodeImage(&output_buffer, vc5_encoder_params, &vc5_image));
    //Temp Write out file for giggles
    char* output_file_path = filePath;
    int len = strlen(filePath);
    output_file_path[(len - 3)] = 'V';
    output_file_path[(len - 2)] = 'C';
    output_file_path[(len - 1)] = '5';
	
    //int fd = open(INPUT_PIPE, O_WRONLY);
   // if (fd){

    //write(fd, &vc5_image.size, sizeof(size_t));
   // write(fd, vc5_image.buffer, vc5_image.size);
	//printf("Wrote %d Bytes\n",vc5_image.size);
   // }
    //close(fd);
    _coll_stream_frame(vc5_image.buffer, vc5_image.size);

  /*if( write_to_file( &vc5_image, output_file_path ) )
        {
            LogPrint("Error writing bitstream to location %s",  output_file_path);
            return -1;
        }*/
    //while(1){}
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

