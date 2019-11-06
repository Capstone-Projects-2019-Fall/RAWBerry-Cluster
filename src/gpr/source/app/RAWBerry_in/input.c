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
    
    
    char dir[] = "/home/pi/Documents/CDNG";
    int status = readFiles(dir);
    

    return status;
	}

int readFiles(char* directory){
	
DIR *dir;
struct dirent *ent;


if ((dir = opendir (directory)) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    
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
    
    


        
        
    printf("Decompressed Size\n", rgb_buffer.size);
    



    //LogPrint("Encoding %.3f secs per frame", encodeImage(&output_buffer, vc5_encoder_params, &vc5_image));
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







