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

char *in_pipe;
int pipe_fd;
int sock_fd;
int stream_fd;


int get_file(char **f, uint32_t *sz2)
{
	int rd = 0;
	int sz;
	if(read(pipe_fd, &sz, sizeof(int)) != 4){
		perror("Failed to read size from pipe");
		exit(-1);	
	}
	printf("Reading %d bytes\n", sz);
	if(sz == -1){
		return 0;
	}
	*f = malloc(sz * sizeof(char));
	while(rd != sz){
		rd += read(pipe_fd, *f + rd, (sz - rd));
	}
	*sz2 = sz;
	return 1;
}




void do_send()
{
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	socklen_t clen;
	int p = 1;
	setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &p, sizeof(p));
	struct sockaddr_in saddr, caddr;
	memset(&saddr, 0, sizeof(saddr));
	memset(&caddr, 0, sizeof(struct sockaddr_in));
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htons(1337);
	if(bind(sock_fd, (struct sockaddr *) &saddr, sizeof(saddr)) != 0){
		perror("Bind failed");
		exit(-1);
	}

	mkfifo(in_pipe, 0666);
	pipe_fd = open(in_pipe, O_RDONLY);
	while(!listen(sock_fd, 1)){
		stream_fd = accept(sock_fd, &caddr, &clen);
		printf("Bound to %s\n", inet_ntoa(caddr.sin_addr));
		while(1){
			char *cur;
			uint32_t sz;
			if(get_file(&cur, &sz)){
				printf("Size: %u\n", sz);
				uint32_t sz2 = htonl(sz);
				printf("Writing: %u\n", sz);
				send(stream_fd, &sz2, sizeof(int), 0);
				send(stream_fd, cur, sz, 0);
				free(cur);
			}else{
				sz = 0;
				sz = htonl(sz);
				send(stream_fd, &sz, sizeof(int), 0);
				exit(0);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc <= 2){
		in_pipe = argv[1];
		do_send();
	}else{
		in_pipe = "/tmp/pipe";
		do_send();
		return 0;
	}
	return 0;
}
