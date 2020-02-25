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
//#include "../../lib/vc5_encoder/vc5_encoder.h"
#include "vc5_encoder.h"
#include "timer.h"
#include "config.h"

#include "convert.h"

static char *_dirname;

static int _fnum = 0;

void read_dir(char *dirname, char *dirout) {

    // structure describing an open directory.
    DIR *dir;
    // returns handle to the directory opened - to be used with readdir()
    dir = opendir(dirname);

    // used to return information about directory entries
    struct dirent *ent;

    // each time readdir() is called with the dir handle, it returns the filename of the next file in the directory
    while ((ent = readdir(dir))) {
        if (*(ent->d_name) == '.') {
            // Force next iteration - filters out current dir and parent dir results (hidden)
            continue;
        }

        // allocate space for path string
        char *fullpath = malloc(strlen(dirname)
                                + strlen(ent->d_name) + 2);
        char *out = malloc(strlen(dirout) + strlen(ent->d_name) + 2);
        if (!fullpath || !out) {
            exit(5);
            /* Uh We Might be F****d here? Whatever */
        }
        sprintf(fullpath, "%s/%s", dirname, ent->d_name);
        sprintf(out, "%s/%s", dirout, ent->d_name);
        convert(fullpath, out);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        read_dir(argv[1], argv[2]);
    } else {
        fprintf(stderr, "Incorrect usage, use: %s [indir] [outdir]\n", argv[0]);
    }
    return 0;
}


