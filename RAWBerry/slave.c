/*
 * ============================================================================
 *
 *       Filename:  slave.c
 *
 *    Description:  Slave data-path impl
 *
 *        Version:  1.0
 *        Created:  10/18/2019 10:11:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Gruda, tuh37025@temple.edu
 *
 * ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <stdint.h>
#include <stdbool.h>
#include "gpr.h"
#include "gpr_buffer.h"
#include <sys/types.h>
#include <stdio.h>

#include "sopool.h"


#define ACTION_FRAME_GET 	1
#define ACTION_REPLY_DONE 	2
#define ACTION_SEND_DONE 	3
#define ACTION_BCAST_ALRT 	4

#define NODE_MASTER 0
#define NODE_COLLECTOR 1
#define TAG_S_RET 1
#define TAG_S_TO  2

#define REPLY_MSG_SUCCESS  0x01

#ifdef USE_NONBLOCK
# define MWAIT nb_wait
# define MPROBE nb_probe
#else 
# define MWAIT MPI_Waitany
# define MPROBE MPI_Probe
#endif

struct slave_m{
	union{ 
		struct{ 
			MPI_Request in;
			MPI_Request reply;
			MPI_Request send;
			MPI_Request bcast;
		};
		MPI_Request arr[4];
	};
};

struct reply{
	uint8_t  message;
	uint8_t  padding[3];
	int32_t payload;
};


static int actions[] = { ACTION_FRAME_GET, ACTION_REPLY_DONE, ACTION_SEND_DONE,
	ACTION_BCAST_ALRT };
static void *datas[4] = {NULL, NULL, NULL, NULL};

static struct sopool reply_pool;

static struct reply rmaster;

void _slave_reply_scs(struct slave_m *s, int32_t framenum)
{
	struct reply *r = &rmaster;
	r->message = REPLY_MSG_SUCCESS;
	r->payload = framenum;
	MPI_Isend(r, sizeof(struct reply), MPI_BYTE, NODE_MASTER,  TAG_S_RET,
			MPI_COMM_WORLD, &s->reply);  
	datas[1] = r;
}

int _slave_wait(struct slave_m *s, int *errc)
{
	int i;
	MPI_Status stat;
	*errc = MWAIT(4, s->arr, &i, &stat);
	s->arr[i] = MPI_REQUEST_NULL;
	return actions[i];
}

static void _recv_frame(struct slave_m *s, gpr_buffer *frame)
{
	printf("RECV FRAME CALLED\n");
	size_t * size = &frame->size;
	MPI_Irecv(size, sizeof(size_t), MPI_BYTE, NODE_MASTER, TAG_S_TO, 
		MPI_COMM_WORLD, &(s->in));
	frame->buffer = malloc(frame->size);
	printf("RECV FRAME SIZE\n", frame->size);
	MPI_Irecv(frame->buffer, frame->size, MPI_BYTE, NODE_MASTER, TAG_S_TO, 
		MPI_COMM_WORLD, &(s->in));
	printf("RECV FRAME FINISHED\n");
}

static void _send_cframe(struct slave_m *s, gpr_buffer *frame)
{
	printf("Sending Compressed Frame\n");
	int errc = 0;
	errc = MPI_Isend(&frame->size, sizeof(size_t), MPI_BYTE, NODE_COLLECTOR, TAG_S_TO, 
		MPI_COMM_WORLD, &(s->send));

	errc = MPI_Isend(&frame->buffer, frame->size, MPI_BYTE, NODE_COLLECTOR, TAG_S_TO, 
		MPI_COMM_WORLD, &(s->send));
	
	if(errc != MPI_SUCCESS){
		//TODO:Error handle
	}
}


void _s_compress(gpr_buffer *in, gpr_buffer *out, int *sz)
{
	gpr_allocator allocator;
    allocator.Alloc = malloc;
    allocator.Free = free;
    
    gpr_parameters params;
    gpr_parameters_set_defaults(&params);
    params.tuning_info.pixel_format = PIXEL_FORMAT_GBRG_12;

	printf("Read:%d Bytes\n", in->size);
	
    gpr_parse_metadata( &allocator, &in, &params );

	gpr_convert_dng_to_gpr( &allocator, &params, &in, &out );
}

int slave(struct cluster_args *params)
{
	int i = 0, errc = 0, frnum = 0;
	int v = 0, sz = 0;
	gpr_buffer input_buffer  = { NULL, 0 };
	gpr_buffer output_buffer  = { NULL, 0 };


	struct slave_m ctl = { .arr = { MPI_REQUEST_NULL, MPI_REQUEST_NULL, 
		MPI_REQUEST_NULL, MPI_REQUEST_NULL } };
	//init_engine(params);
	sopool_init(&reply_pool, sizeof(struct reply), 3, 0);
	_slave_reply_scs(&ctl, 0);
	_recv_frame(&ctl, &input_buffer);
	while(!slave_done()){
		i = _slave_wait(&ctl, &errc);
		if(errc != MPI_SUCCESS){
			//TODO:Handle error
		}
		/*tprintf("Slave action: %d\n", i);*/
		switch(i){
		case ACTION_FRAME_GET:
			if(output_buffer.buffer == NULL){ 
				_s_compress(&input_buffer, &output_buffer, &sz);
				_send_cframe(&ctl, &output_buffer);
				_slave_reply_scs(&ctl, frnum);
				_recv_frame(&ctl, &input_buffer);
			}else{
				v = 1;
			}
			break;
		case ACTION_REPLY_DONE:
			break;
		case ACTION_SEND_DONE:
			free(output_buffer.buffer);
			output_buffer.buffer = NULL;
			if(v){
				v = 0;
				_s_compress(&input_buffer, &output_buffer, &sz);
				_slave_reply_scs(&ctl, frnum);
				_recv_frame(&ctl, &input_buffer);
			}
			break;
		case ACTION_BCAST_ALRT:
			break;
		
		default:
			//ERROR
			break;
		}
	}
	return 0;
}

int slave_done(void)
{
	return 0;
}
