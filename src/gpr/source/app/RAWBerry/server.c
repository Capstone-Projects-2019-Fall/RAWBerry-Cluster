/*
 * ============================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/2019 04:23:51 PM
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
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "cluster.h"


#define EXAMPLE_BUFFER_SIZE 10
#define INPUT_WIDTH 1952
#define INPUT_HEIGHT 1112
#define INPUT_PIPE "/tmp/pipe"
#define BUFF_SIZE 400000000



int init_engine(struct cluster_args *params)
{

	return 0;
}

int init_stream_server(struct cluster_args *params)
{
	printf("Opening Pipe\n");
	mkfifo(INPUT_PIPE, 0666);
	int fd = open(INPUT_PIPE, O_WRONLY);
	printf("Pipe Open");
	
	int pid = fork();

	if ( pid == 0 ) {
		execlp( "../rtsp/rtsp", "", NULL);
	}

	return 0;
}
