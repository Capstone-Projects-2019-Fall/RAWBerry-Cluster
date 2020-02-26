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
#include <sys/socket.h>
#include <netinet/in.h>


#include "gpr.h"
#include "gpr_allocator.h"
#include "gpr_buffer.h"
//#include "../../lib/vc5_encoder/vc5_encoder.h"
#include "vc5_encoder.h"
#include "timer.h"
#include "config.h"

#include "convert.h"
#include "server.h"

int main(int argc, char *argv[]) {
    if (argc == 3) {
        send_dir(argv[1], argv[2]);
    } else {
        fprintf(stderr, "Incorrect usage, use: %s [indir] [outdir]\n", argv[0]);
    }
    return 0;
}


