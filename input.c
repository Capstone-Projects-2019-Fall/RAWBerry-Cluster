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

#include "gpr.h"
#include "gpr_allocator.h"
#include "gpr_buffer.h"

int readFiles(char* directory);
int openImage(char* filePath);

int main(int argc, char **argv)
{
	char dir[] = "/home/pi/Documents/CDNG";
	return readFiles(dir);
	}

int readFiles(char* directory){
	
DIR *dir;
struct dirent *ent;


if ((dir = opendir (directory)) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    
    //Get us a string with the full path so we can open file
	char *fullpath = malloc(strlen(directory)+ strlen(ent->d_name) + 2);
	if (fullpath == NULL) { /* Uh We Might be F****d here? Whatever */ }
	sprintf(fullpath, "%s/%s", directory, ent->d_name);
	openImage(fullpath);
	/* use fullpath */
	free(fullpath);
    //Do Things with files
    
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
    
    
    int success = gpr_convert_dng_to_gpr( &allocator, &params, &input_buffer, &output_buffer );
    
    printf ("%s\n", filePath);
	
    gpr_parameters_destroy(&params, allocator.Free);
	
    if( success == 0 )
    {
        printf("Conversion failed \n");
        return -1;
    }
    
    //Temp Write out file for giggles
    char* output_file_path = filePath;
    int len = strlen(filePath);
    output_file_path[(len - 3)] = 'G';
    output_file_path[(len - 2)] = 'P';
    output_file_path[(len - 1)] = 'R';

    write_to_file( &output_buffer, output_file_path );
    return 0;
}


