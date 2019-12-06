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
#define _GNU_SOURCE
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

char *out_pipe;
char *in_dir;
int pipe_fd;

void write_file(char *f, int sz)
{
	int bytes_written = 0;

	write(pipe_fd, &sz, sizeof(int));
	write(pipe_fd, f, sz);
}

static int _filter(const struct dirent *d)
{
	return *d->d_name != '.';
}

void do_dir()
{
	mkfifo(out_pipe, 0666);
	pipe_fd = open(out_pipe, O_WRONLY);

	struct dirent **list;
	int len, i = 0;
	len = scandir(in_dir, &list, _filter, versionsort);
	if (len != -1){
		for(; i < len; i++){
			char *path = malloc(strlen(in_dir) + 50);
			sprintf(path, "%s/%s\0", in_dir, list[i]->d_name);
			int f = open(path, O_RDONLY);
			int l = (int) lseek(f, 0l, SEEK_END);
			lseek(f, 0l, SEEK_SET);
			char *file = malloc(l * sizeof(char));
			int re = read(f, file, l);
			printf("Read %d bytes\n", re);
			close(f);
			write_file(file, l);
			free(file);
			free(path);
		} 
		free(list);
		int w = -1;
		write(pipe_fd, &w, sizeof(int));
		close(pipe_fd);
	}else{
		/* could not open directory */
		perror ("");
	}
}

int main(int argc, char *argv[])
{
	if(argc == 3){
		out_pipe = argv[1];
		in_dir = argv[2];
		do_dir();
	}else{
		return -1;
	}
	return 0;
}
