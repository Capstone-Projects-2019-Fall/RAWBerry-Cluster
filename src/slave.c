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

#include "cluster.h"
#include "util.h"
#include "sopool.h"

#define ACTION_FRAME_GET 	1
#define ACTION_REPLY_DONE 	2
#define ACTION_SEND_DONE 	3
#define ACTION_BCAST_ALRT 	4

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
	*errc = MPI_Waitany(4, s->arr, &i, &stat);
	s->arr[i] = MPI_REQUEST_NULL;
	return actions[i];
}

static void _recv_frame(struct slave_m *s, void *frame)
{
	MPI_Irecv(frame, FRAME_RAW_SIZEB, MPI_BYTE, NODE_MASTER, TAG_S_TO, 
		MPI_COMM_WORLD, &(s->in));
}

static void _send_cframe(struct slave_m *s, void *cframe, int sz)
{
	int errc = 0;
	errc = MPI_Isend(cframe, sz, MPI_BYTE, NODE_COLLECTOR, TAG_S_TO, 
		MPI_COMM_WORLD, &(s->send));
	if(errc != MPI_SUCCESS){
		//TODO:Error handle
	}
}

#ifndef TEST
void _s_compress(void *in, void **out)
{
	/* TODO: Hook this up right somehow
	vc5_encoder_parameters params;
	vc5_encoder_process(&params, in, NULL, out);
	 */
}
#endif

int slave(struct cluster_args *params)
{
	int i = 0, errc = 0, frnum = 0;
	int v = 0, sz = 0;
	void *frame_in = NULL;
	void *frame_out = NULL;
	frame_in = malloc(FRAME_RAW_SIZEB);
	struct slave_m ctl = { .arr = { MPI_REQUEST_NULL, MPI_REQUEST_NULL, 
		MPI_REQUEST_NULL, MPI_REQUEST_NULL } };
	init_engine(params);
	sopool_init(&reply_pool, sizeof(struct reply), 3, 0);
	_slave_reply_scs(&ctl, 0);
	_recv_frame(&ctl, frame_in);
	while(!slave_done()){
		i = _slave_wait(&ctl, &errc);
		if(errc != MPI_SUCCESS){
			//TODO:Handle error
		}
		/*tprintf("Slave action: %d\n", i);*/
		switch(i){
		case ACTION_FRAME_GET:
			if(frame_out == NULL){ 
				_s_compress(frame_in, &frame_out, &sz);
				_send_cframe(&ctl, frame_in, sz);
				_slave_reply_scs(&ctl, frnum);
				_recv_frame(&ctl, frame_in);
			}else{
				v = 1;
			}
			break;
		case ACTION_REPLY_DONE:
			break;
		case ACTION_SEND_DONE:
			free(frame_out);
			frame_out = NULL;
			if(v){
				v = 0;
				_s_compress(frame_in, &frame_out);
				_slave_reply_scs(&ctl, frnum);
				_recv_frame(&ctl, frame_in);
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
