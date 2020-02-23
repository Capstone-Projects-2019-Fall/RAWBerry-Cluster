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

/// tsvr - SERVER

char *in_pipe;
int pipe_fd;
int sock_fd;
int stream_fd;


int get_file(char **f, uint32_t *sz2) {
    int rd = 0;
    int sz;
    if (read(pipe_fd, &sz, sizeof(int)) != 4) {
        perror("Failed to read size from pipe");
        exit(-1);
    }
    printf("Reading %d bytes\n", sz);
    if (sz == -1) {
        return 0;
    }
    *f = malloc(sz * sizeof(char));
    while (rd != sz) {
        rd += read(pipe_fd, *f + rd, (sz - rd));
    }
    *sz2 = sz;
    return 1;
}


void do_send() {
    // socket() creates an endpoint for communication, returns a file descriptor
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    // AF_INET is an address family that is used to designate the type of
    // addresses that your socket can communicate with

    // TCP (SOCK_STREAM) is a connection-based protocol. The connection is
    // established and the two parties have a conversation until the connection
    // is terminated by one of the parties or by a network error.
    if (sock_fd == -1) {
        perror("Cannot open socket");
        exit(1);
    }
    // IDK what this does... socket length? 32 bits
    socklen_t clen;
    int p = 1;
    // Socket options set
    p = setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &p, sizeof(p));
    if (p == -1) {
        perror("Cannot set reuseaddr");
        exit(-1);
    }

    struct sockaddr_in saddr, caddr;

    memset(&saddr, 0, sizeof(saddr));
    memset(&caddr, 0, sizeof(struct sockaddr_in));

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(1337); // really..

    // bind() assigns the address specified by saddr to sock_fd - a file descriptor
    if (bind(sock_fd, (struct sockaddr *) &saddr, sizeof(saddr)) != 0) {
        perror("Bind failed");
        exit(-1);
    }

    // Make a FIFO pipe
    // mode_t of 0666, everyone (the file's owner, the file's group, and others) can read and write to the file
    mkfifo(in_pipe, 0666);

    // returns FD of FIFO in_pipe - must be open at both ends simultaneously before input/output operations
    // typically blocks until some other process opens the same FIFO for writing, and vice versa
    pipe_fd = open(in_pipe, O_RDONLY);
    if (pipe_fd == -1) {
        perror("Cannot open pipe");
        exit(1);
    }

    // true if number == 0, which listen() returns upon success, so loop indef..?
    // 1 is max length to which queue of pending connections for sock_fd may grow
    while (!listen(sock_fd, 1)) {

        // accept() extracts the first connection request on the queue of pending connections
        // for the listening socket sock_fd, creates a new connected socket, and returns a
        // new file descriptor referring to that socket
        stream_fd = accept(sock_fd, &caddr, &clen);

        // The inet_ntoa() function converts the Internet host address in (caddr.sin_addr),
        // given in network byte order, to a string in IPv4 dotted-decimal notation.
        // The string is returned in a statically allocated buffer, which
        // subsequent calls will overwrite.
        printf("Bound to %s\n", inet_ntoa(caddr.sin_addr));


        while (1) {
            char *cur;
            // uint32_t is a numeric type that guarantees 32 bits
            uint32_t sz;
            if (get_file(&cur, &sz)) {
                printf("Size: %u\n", sz);
                uint32_t sz2 = htonl(sz);
                printf("Writing: %u\n", sz);
                send(stream_fd, &sz2, sizeof(int), 0);
                send(stream_fd, cur, sz, 0);
                free(cur);
            } else {
                sz = 0;
                sz = htonl(sz);
                send(stream_fd, &sz, sizeof(int), 0);
                exit(0);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        in_pipe = argv[1]; // first argument is the location of the in_pipe
        do_send();
    } else {
        in_pipe = "/tmp/pipe";
        do_send();
        return 0;
    }
    return 0;
}
