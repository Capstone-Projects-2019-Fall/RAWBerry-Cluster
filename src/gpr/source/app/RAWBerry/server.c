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
#include <errno.h>
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

#define OUT_DIR "./out"

int pipe_fd;

int init_engine(struct cluster_args *params)
{

	return 0;
}

int init_stream_server(struct cluster_args *params)
{
	printf("Opening Pipe\n");
	mkfifo(INPUT_PIPE, 0666);
	printf("Pipe Open");
	
	int pid = fork();

	if ( pid == 0 ) {
		execlp( "./source/app/rtsp/rtsp", "", NULL);
	}

	return 0;
}

void stream_frame(void *frame, int sz, int frnum)
{
	/* Temp output */
	char fname[50];
	snprintf(fname, 50, "%s/fr%d.vc5", OUT_DIR, frnum);
	int fd = open(fname, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
	int wrote = write(fd, frame, sz);
	printf("Wrote %d bytes to %s\n", wrote, fname);
	if(wrote == -1){
		perror("Write error");
	}
	/*int bytes_written = 0;*/

	/*int pipe_fd = open("/tmp/pipe", O_WRONLY);*/
	/*write(pipe_fd, &sz, sizeof(int));*/

	/*while (bytes_written != sz){*/
		/*puts("Write");*/
		/*bytes_written += write(pipe_fd, frame, (sz - bytes_written));*/
	/*}*/
	/*close(pipe_fd);*/
	/*printf("Wrote: %d Bytes\n", bytes_written);*/

}
