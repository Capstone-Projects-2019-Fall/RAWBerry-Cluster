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

char *in_pipe;
char *out_dir;
int pipe_fd;

int get_file(char **f, int *sz)
{
	int rd = 0;

	if(read(pipe_fd, sz, sizeof(int)) != 4){
		exit(-1);	
	}
	printf("Reading %d bytes\n", *sz);
	if(*sz == -1){
		return 0;
	}
	*f = malloc(*sz * sizeof(char));
	while(rd != *sz){
		rd += read(pipe_fd, *f + rd, (*sz - rd));
	}
	return 1;
}

void do_dir()
{
	char *file;
	char *fname = malloc(strlen(out_dir) + 50);
	int sz;
	int num = 0;
	pipe_fd = open(in_pipe, O_RDONLY);
	while(get_file(&file, &sz)){
		sprintf(fname, "%s/n%d", out_dir, num);
		int fd = open(fname, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		write(fd, file, sz);
		close(fd);
		free(file);
		num++;
	}
	close(pipe_fd);
}

int main(int argc, char *argv[])
{
	if(argc == 3){
		in_pipe = argv[1];
		out_dir = argv[2];
		do_dir();
	}else{
		return -1;
	}
	return 0;
}
