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

int fd;


int readFiles(char* directory);
int openImage(char* filePath);


int main(int argc, char **argv)
{
	char dir[] = "./input";
	int status = readFiles(dir);
	return status;
}

void read_file(char *directory, char *name)
{
	CvMat * image;
	//Get us a string with the full path so we can open file
	char *fullpath = (char *) malloc(strlen(directory)+ strlen(name) + 2);
	if (fullpath == NULL) { exit(-5); }
	sprintf(fullpath, "%s/%s", directory, name);
	int success = openImage(fullpath);
	if(success ==0){
		printf("Reading: %s\n", fullpath);
		image = cvLoadImageM(fullpath, CV_LOAD_IMAGE_COLOR);
		cvShowImage( "Display window", image );            
		cvWaitKey(42); 
	}
	/* use fullpath */
	free(fullpath);
}

static int _filter(const struct dirent *d)
{
	return *d->d_name != '.';
}

int readFiles(char* directory)
{
	
	DIR *dir;
	struct dirent *ent;
	cvNamedWindow( "Display window", CV_WINDOW_AUTOSIZE ); 
/*  

	gpr_buffer input_buffer  = { NULL, 0 };
	_read_pipe(&input_buffer);

	int success = openImage(&input_buffer);
	image = cvLoadImageM(fullpath, CV_LOAD_IMAGE_COLOR);
	if(success ==0){
	    cvShowImage( "Display window", image );            
	    cvWaitKey(42); 
	}
	free(ent[i]);
}
*/
	struct dirent **list;
	int len, i = 0;
	len = scandir(directory, &list, _filter, versionsort);
	if (len != -1){
		/* print all the files and directories within directory */
		for(; i < len; i++){
			read_file(directory, list[i]->d_name);
		} 
		free(list);
	}else{
		/* could not open directory */
		perror ("");
		return EXIT_FAILURE;
	}
	return 0;
}

int openImage(char * filePath)
{
    
	gpr_allocator allocator;
	allocator.Alloc = malloc;
	allocator.Free = free;

	gpr_parameters params;
	gpr_parameters_set_defaults(&params);

	gpr_buffer output_buffer = { NULL, 0 };
	gpr_buffer input_buffer  = { NULL, 0 };
	printf("Reading: %s\n", filePath);
	if( read_from_file( &input_buffer, filePath, allocator.Alloc, allocator.Free ) != 0 )
	{
		return 0;
	}

	printf("Read:%d Bytes\n", input_buffer.size);
	puts("Reading Metadata\n");
	    
	gpr_parse_metadata( &allocator, &input_buffer, &params );
	puts("Read Metadata\n");
	gpr_rgb_buffer rgb_buffer = { NULL, 0, 0, 0 };
	GPR_RGB_RESOLUTION rgb_resolution = GPR_RGB_RESOLUTION_HALF;

	int rgb_file_bits = 16;
	puts("Converting\n");
	int success = gpr_convert_gpr_to_rgb( &allocator, rgb_resolution, rgb_file_bits,  &input_buffer, &rgb_buffer );

	puts("Converted\n");
	char header_text[100];

	sprintf( header_text, "P6\n%ld %ld\n65535\n", rgb_buffer.width, rgb_buffer.height );
		
	output_buffer.size   = rgb_buffer.size + strlen( header_text );
	output_buffer.buffer = allocator.Alloc( output_buffer.size );
	char* buffer_c = (char*)output_buffer.buffer;
		
	memcpy( buffer_c, header_text, strlen( header_text ) );
	memcpy( buffer_c + strlen( header_text ), rgb_buffer.buffer, rgb_buffer.size );
	    
	printf("Decompressed Size\n", rgb_buffer.size);

	//LogPrint("Encoding %.3f secs per frame", encodeImage(&output_buffer, vc5_encoder_params, &vc5_image));
	//Temp Write out file for giggles
	char* output_file_path = filePath;
	int len = strlen(filePath);
	output_file_path[(len - 3)] = 'p';
	output_file_path[(len - 2)] = 'p';
	output_file_path[(len - 1)] = 'm';
	if(write_to_file(&output_buffer, output_file_path)){
        	printf("Error writing bitstream to location %s",  output_file_path);
        	return -1;
        }
   	printf("Wrote %d Bytes\n",rgb_buffer.size);
    	return 0;
}

/*  
void _read_pipe(gpr_buffer * input){
int bytes_read = 0;
    
    int pipe_fd = open(INPUT_PIPE, O_RDONLY);
    if (pipe){
        //get size of frame
        read(pipe_fd, input.size, sizeof(int));
        printf("Expected frame size: %d \n", len);
        //malloc mem for buffer
        buffer = (unsigned char *)malloc(len);

        while (bytes_read != len){
            bytes_read += read(pipe_fd, (input.buffer+bytes_read), (len - bytes_read));
            printf("Bytes Read: %d \nFrame Size: %d\n", bytes_read, len);
        }
        
    }
}
*/






