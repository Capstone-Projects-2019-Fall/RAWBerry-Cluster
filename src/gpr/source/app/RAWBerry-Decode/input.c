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
    
    
    char dir[] = "/home/pi/Documents/VC5";
    int status = readFiles(dir);
    

    return status;
	}

int readFiles(char* directory){
	
DIR *dir;
struct dirent *ent;




if ((dir = opendir (directory)) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    puts("die");
    //Get us a string with the full path so we can open file
	char *fullpath = malloc(strlen(directory)+ strlen(ent->d_name) + 2);
	if (fullpath == NULL) { /* Uh We Might be F****d here? Whatever */  return -1; }
	sprintf(fullpath, "%s/%s", directory, ent->d_name);
	openImage(fullpath);
    
	/* use fullpath */
	free(fullpath);

    
}
  
 closedir (dir);
} else {
  /* could not open directory */
  perror ("");
 return EXIT_FAILURE;
}
	return 0;
}

int openImage(char* filePath){
    
    gpr_allocator allocator;
    allocator.Alloc = malloc;
    allocator.Free = free;
    
    gpr_parameters params;
    gpr_parameters_set_defaults(&params);
    
    gpr_buffer input_buffer  = { NULL, 0 };
    gpr_buffer output_buffer = { NULL, 0 };
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

  if( write_to_file( &output_buffer, output_file_path ) )
        {
            LogPrint("Error writing bitstream to location %s",  output_file_path);
            return -1;
        }
    printf("Wrote %d Bytes\n",rgb_buffer.size);

    return 0;
}







