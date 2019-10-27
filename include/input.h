/*
    input.h
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
#include "buffer.h"

#define BUFFER_SIZE 10
#define DIR_LENGTH 64


struct read_args {
    char dir[DIR_LENGTH];//string of directory to ingest to buffer
    buf_handle_t buf;
};

static struct argp_option options[] = {
    //here we can choose what options to encore for cluster
    //some of these may be passed to cluster via payload.ops
};
struct arguments {
    //argument entities
    char *args[2]; //these are our DIRECTORY and CONFIG arguments
    //other variables can be added here for more args, options, etc
};

int readFiles(char* directory, buf_handle_t buf);
int openImage(char* filePath, buf_handle_t buf);
void print_buffer_status(buf_handle_t buf);

