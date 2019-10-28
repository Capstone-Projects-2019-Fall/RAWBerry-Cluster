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
#include "decode.h"

#define EXAMPLE_BUFFER_SIZE 10
#define INPUT_WIDTH 1952
#define INPUT_HEIGHT 1112
#define INPUT_PIPE "/tmp/pipe"
#define BUFF_SIZE 400000000



int decodeImage(const char* frame, int size){
	
        CODEC_ERROR error = CODEC_ERROR_OKAY;
    
        vc5_decoder_parameters vc5_decoder_params;
        vc5_decoder_parameters_set_default(&vc5_decoder_params);
        vc5_decoder_params.enabled_parts = VC5_ENABLED_PARTS;
        vc5_decoder_params.mem_alloc     = malloc;
        vc5_decoder_params.mem_free      = free;

        gpr_buffer raw_image = { NULL, 0  };
        gpr_rgb_buffer rgb_image = { NULL, 0, 0, 0  };
        
        gpr_buffer vc5_image = { &frame, size  };
    
        TIMER timer; // Performance timer
        InitTimer(&timer);
    
        StartTimer(&timer);
        

        
        vc5_decoder_process( &vc5_decoder_params, &vc5_image, &raw_image, &rgb_image );
        
        StopTimer(&timer);
        
        printf("Decompressed Size", raw_image.size);
    return 0;
}


