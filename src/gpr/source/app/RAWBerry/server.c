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

static char *rtsp_loc;
static char *out_dir;
static int use_rtsp;

static int _pblen;
static char *_pbuff;

int init_engine(struct cluster_args *params) {

    return 0;
}

int pipe_fd;

int init_stream_server(struct cluster_args *params) {
    use_rtsp = params->use_rtsp;
    rtsp_loc = params->rtsp_loc;
    out_dir = params->out_dir;
    if (use_rtsp) {
        mkfifo(INPUT_PIPE, 0666);
        int pid = fork();


        if (pid == 0) {
            execlp(rtsp_loc, rtsp_loc, INPUT_PIPE, "out", NULL);
            fprintf(stderr, "Failed to open rtsp at %s\n", rtsp_loc);
            exit(-1);
        }
        pipe_fd = open("/tmp/pipe", O_WRONLY);
    } else {
        _pblen = strlen(out_dir) + 50;
        _pbuff = malloc(_pblen);
    }

    return 0;
}


void stream_frame(void *frame, int sz, int frnum) {
    /* Temp output */
    if (!use_rtsp) {
        snprintf(_pbuff, _pblen, "%s/fr%d.vc5", OUT_DIR, frnum);
        int fd = open(_pbuff, O_WRONLY | O_CREAT,
                      S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
        int wrote = write(fd, frame, sz);
        VLOGF("Wrote %d bytes to %s\n", wrote, _pbuff);
        if (wrote == -1) {
            perror("Write error");
        }
    } else {
        int bytes_written = 0;

        write(pipe_fd, &sz, sizeof(int));

        while (bytes_written != sz) {
            bytes_written += write(pipe_fd, frame,
                                   (sz - bytes_written));
        }
        VLOGF("Wrote: %d Bytes\n", bytes_written);
    }
}
