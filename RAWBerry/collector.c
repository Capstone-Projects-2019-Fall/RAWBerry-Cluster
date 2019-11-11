/*
 * =============================================================================
 *
 *       Filename:  collector.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/19/2019 07:28:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Gruda (mg), matthewgruda@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include <stdlib.h>
#include <mpi.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

#include "cluster.h"
#include "util.h"


#define A_FRAME_AVALIBLE 1
#define A_FRAMETX_DONE   2
#define A_BCAST_RECV 	 3
#define STREAM_PIPE "/tmp/pipe"

#define TAG_S_TO  2
#define REPLY_MSG_SUCCESS  0x01
#define REPLY_MSG_LFRAME     0x02
#define REPLY_MSG_EXIT	    0x03

static int nslaves;
static MPI_Request *reqs;
static void **datas;
static uint32_t _lframe = UINT32_MAX;

int count =0;

static int _coll_select(MPI_Status *s, int *action)
{
	int er = 0, idx, flag;
       /* er = MPI_Testany(nslaves, reqs, &idx, &flag, s);*/
	/*if(flag){*/
		/**action = A_FRAMETX_DONE;*/
		/*return er;*/
	/*}*/
	er = MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, s);
	if(s->MPI_TAG == TAG_S_TO){
		*action = A_FRAME_AVALIBLE;
	}else if(s->MPI_TAG == TAG_B_ALRT){
		*action = A_BCAST_RECV;
	}
	return er;
}

int _coll_recv_frame(MPI_Status *s, gpr_buffer *frame)
{
	printf("RECV FRAME CALLED\n");
	size_t * size = &frame->size;

	int errc = MPI_Recv(size, sizeof(size_t), MPI_BYTE, s->MPI_SOURCE, s->MPI_TAG, 
			MPI_COMM_WORLD, s);
	frame->buffer = malloc(frame->size);
	printf("RECV FRAME SIZE\n", frame->size);
	errc = MPI_Recv(frame->buffer, frame->size, MPI_BYTE, s->MPI_SOURCE, s->MPI_TAG, 
			MPI_COMM_WORLD, s);
	printf("RECV FRAME FINISHED\n");
	return errc;
}

void _coll_stream_frame(gpr_buffer *frame)
{
	//uint32_t fnum = *(uint32_t *)(frame);
	printf("Streaming frame %d\n", count);

	char path[] = "/tmp/Frame.GPR";
    write_to_file( &frame, path );
	/*stream_frame((uint8_t *)frame + 4, sz - 4, fnum);*/
	//if(fnum == _lframe){
		//struct reply r = { .message = REPLY_MSG_EXIT, .payload = 0 };
		//c_bcast_send(&r);
		//exit(0);
	//}
	
}

static struct reply *_coll_bcast_recv(MPI_Status *st)
{
	struct reply *r = malloc(sizeof(*r));
	MPI_Recv(r, sizeof(*r), MPI_BYTE, st->MPI_SOURCE, TAG_B_ALRT, MPI_COMM_WORLD, st);
	if(r->message == REPLY_MSG_LFRAME){
		_lframe = r->payload;
	}
	return r;
}

/*void _coll_stream_frame(void *frame, int sz)*/
/*{*/
	/*[> write frame to streaming server's input pipe <]*/
	/*int pipe_fd = open(STREAM_PIPE, O_WRONLY);*/
	/*write(pipe_fd, &sz, sizeof(int));*/
	/*write(pipe_fd, frame, sz);*/
	/*close(pipe_fd);*/
	/*tprintf("%s: %d\n", ((char*)frame)+4, *(int*)frame);*/
/*}*/

int collector_done(void)
{
	return 0;
}

int collector(struct cluster_args *args)
{
	
	int errc, i, sz;
	gpr_buffer input_buffer  = { NULL, 0 };
	MPI_Status stat;
	nslaves = num_nodes - NSLAVE_START;
	reqs = malloc(sizeof(MPI_Request) * nslaves);
	for(i = 0; i < nslaves; i++){
		*(reqs + i) = MPI_REQUEST_NULL;
	}
	//errc = init_stream_server(args);
	
	while(!collector_done()){
		errc = _coll_select(&stat, &i);
		if(errc != MPI_SUCCESS){
			//TODO:Error handle
		}
		/*tprintf("Collector action: %d\n", i);*/
		switch(i){
			case A_FRAME_AVALIBLE:
				_coll_recv_frame(&stat, &input_buffer);
				count++;
				_coll_stream_frame(&input_buffer);
				free(input_buffer.buffer);
				break;
			case A_BCAST_RECV:
				_coll_bcast_recv(&stat);
				break;
		}

	}
	return 0;
}
