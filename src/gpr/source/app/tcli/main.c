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
#define _DEFAULT_SOURCE
#define _BSD_SOURCE
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
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

char *out_pipe = "/tmp/ipipe";
char *in_addr;
int pipe_fd;
int stream_fd;

void write_file(char *f, int sz)
{
	int bw = 0;
	
	write(pipe_fd, &sz, sizeof(int));
	while(bw < sz)
		bw += write(pipe_fd, f, sz);
}


int get_file_t(char **f, uint32_t *sz)
{
	int rd = 0;

	if(recv(stream_fd, sz, sizeof(int), 0) != 4){
		perror("Failed to get connection");
		exit(-1);	
	}
	*sz = ntohl(*sz);
	printf("Reading %u bytes\n", *sz);
	if(*sz == 0){
		return 0;
	}
	*f = malloc(*sz * sizeof(char));
	while(rd != *sz){
		rd += recv(stream_fd, *f + rd, (*sz - rd), 0);
	}
	return 1;
}

void do_get()
{
	mkfifo(out_pipe, 0666);
	pipe_fd = open(out_pipe, O_WRONLY);
	stream_fd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in saddr;
	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(1337);
	if(!inet_aton(in_addr, &saddr.sin_addr)){
		printf("Bad ip address: %s\n", in_addr);
		exit(-1);
	}
	if(connect(stream_fd, (struct sockaddr *) &saddr, sizeof(saddr))){
		perror("Failed to connect");
		exit(-2);
	}
	char *f;
	uint32_t sz = 0;
	while(get_file_t(&f, &sz)){
		write_file(f, sz);
		free(f);
		sz = 0;
	}
	sz = -1;
	write(pipe_fd, &sz, sizeof(int));
	close(pipe_fd);
}

int main(int argc, char *argv[])
{
	if(argc == 2){
		in_addr = argv[1];
		do_get();
	}else{
		in_addr = "127.0.0.1";
		do_get();
	}
	return 0;
}
