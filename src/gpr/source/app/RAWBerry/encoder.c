/*
 * ============================================================================
 *
 *       Filename:  encoder.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/30/2019 01:25:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Gruda, tuh37025@temple.edu
 *
 * ============================================================================
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

int encodeImage(gpr_buffer * output_buffer, vc5_encoder_parameters * vc5_encoder_params, gpr_buffer * vc5_image){
	TIMER timer;
    	InitTimer(&timer);
	
	StartTimer(&timer);
        vc5_encoder_process( vc5_encoder_params, output_buffer, vc5_image, NULL );
        StopTimer(&timer);
        assert( vc5_image->buffer && vc5_image->size > 0 );
	return TimeSecs(&timer);

}

int encode(void *in, void **out, int *sz)
{
	
	gpr_buffer input = { in, FRAME_RAW_SIZEB - 4 };
	gpr_buffer vc5_image = { NULL, 0  };
	     
	vc5_encoder_parameters vc5_encoder_params;
	vc5_encoder_parameters_set_default(&vc5_encoder_params);
	vc5_encoder_params.enabled_parts    = VC5_ENABLED_PARTS;
	vc5_encoder_params.input_width      = INPUT_WIDTH;
	vc5_encoder_params.input_height     = INPUT_HEIGHT;
	vc5_encoder_params.input_pitch      = INPUT_WIDTH * 2;
	vc5_encoder_params.mem_alloc        = malloc;
	vc5_encoder_params.mem_free         = free;

	encodeImage(&input, &vc5_encoder_params, &vc5_image);
	//LogPrint("Encoding %.3f secs per frame", encodeImage(&output_buffer, vc5_encoder_params, &vc5_image));
	//Temp Write out file for giggles
	*out = vc5_image.buffer;
	*sz = vc5_image.size;
}




