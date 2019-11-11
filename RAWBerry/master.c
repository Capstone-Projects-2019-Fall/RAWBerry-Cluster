/*
 * ============================================================================
 *
 *       Filename:  master.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2019 01:02:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Gruda, tuh37025@temple.edu
 *
 * ============================================================================
 */

#include <mpi.h>
#include <stdbool.h>
#include <stdint.h>


#include "util.h"
#include "sopool.h"

#include "gpr_buffer.h"

#define TAG_S_RET 1
#define TAG_S_TO  2


#define ACTION_SLAVE_AVALIBLE 1
#define ACTION_SLAVE_SENT 2

#ifdef USE_NONBLOCK
# define MWAIT nb_wait
# define MPROBE nb_probe
#else 
# define MWAIT MPI_Waitany
# define MPROBE MPI_Probe
#endif

struct status_m{
	MPI_Request *reqs;
	int *actions;
	int *nodes;
	void **data;
	int mvals;
};

struct reply{
	uint8_t  message;
	uint8_t  padding[3];
	int32_t payload;
};

static int _fn = 0;

static struct sopool frame_pool;
static struct sopool reply_pool;

#ifndef TEST


# ifdef UNUSED
int get_frame(void **frame)
{
	int res = 0;
	if(!buf_empty(_in)){
		res = buf_get(_in, *frame);
	}
	return res;
}
# endif 
#endif  // NDEF TEST 

void _init_status(struct status_m *s, int mvals)
{
	int i = 0;
	s->mvals = mvals;
	s->reqs = calloc(sizeof(MPI_Request), s->mvals);
	for(; i < mvals; i++){
		*(s->reqs + i) = MPI_REQUEST_NULL;
	}
	s->actions = calloc(sizeof(int), s->mvals);
	s->nodes = calloc(sizeof(int), s->mvals);
	s->data = malloc(sizeof(void *) * s->mvals);
}

int _create_resp(struct status_m *s, int action, int node)
{
	int i = 0;
	while((*(s->reqs + i) != MPI_REQUEST_NULL) && i < s->mvals)
		i++;
	*(s->actions + i) = action;
	*(s->nodes + i) = node;
	return i;
}

int _wait_status(struct status_m *s, int *errc)
{
	int i; 
	MPI_Status stat;
	*errc = MWAIT(s->mvals, s->reqs, &i,  &stat);
	*(s->reqs + i) = MPI_REQUEST_NULL;
	return i;
}

void _send_frame(struct status_m *s, int to, gpr_buffer *frame)
{
	int c, err;
	c = _create_resp(s, ACTION_SLAVE_SENT, to);
	printf("Sending Size\n");
	err = MPI_Isend(&frame->size, sizeof(size_t), MPI_BYTE, to, TAG_S_TO, 
			MPI_COMM_WORLD, s->reqs + c);
	printf("Sending Data\n");
	err = MPI_Isend(&frame->buffer, frame->size, MPI_BYTE, to, TAG_S_TO, 
			MPI_COMM_WORLD, s->reqs + c);
	*(s->data + c) = frame;
	if(err != MPI_SUCCESS){

	}
}

void _irecv_reply(struct status_m *s, int action, int node)
{
	int c = _create_resp(s, action, node);
	struct reply *r = sopool_get_new(&reply_pool);
	s->data[c] = r;
	MPI_Irecv(r, sizeof(struct reply), MPI_INT, node, TAG_S_RET,
			MPI_COMM_WORLD, &(s->reqs[c]));
}


static int _master_get_frame(gpr_buffer *frame)
{
	get_frame(&frame);
	return 0;
}

int master(struct cluster_args *params, int slaves)
{
	int si = 0, i = 0, c = 0;
	int count = 0;
	int errorc = 0;
	struct status_m statm;
	void *frame = NULL, *tmp;
	//create gpr_buffer struct
	gpr_buffer input_buffer  = { NULL, 0 };
	sopool_init(&reply_pool, sizeof(struct reply), slaves, 0);
	_init_status(&statm, slaves * 2 + 2);
	si = init_input(params);
	printf("Read First Frame\n");
	_master_get_frame(&input_buffer);

	for(i = 0; i < slaves; i++){
		_irecv_reply(&statm, ACTION_SLAVE_AVALIBLE, 2 + i);

	}
	while(!master_done()){
		i = _wait_status(&statm, &errorc);	
		if(errorc != MPI_SUCCESS){
			//TODO:ERROR HANDLER
		}
		switch(statm.actions[i]){
			case ACTION_SLAVE_AVALIBLE:
				sopool_return(&reply_pool, statm.data[i]);
				printf("Sending Frame%d\n", count);
				_send_frame(&statm, statm.nodes[i], &input_buffer);
				count++;
				printf("Getting Frame\n"); 
				_master_get_frame(&input_buffer);
				break;
			case ACTION_SLAVE_SENT:
				tmp = statm.data[i];
				//free(tmp);
				_irecv_reply(&statm, ACTION_SLAVE_AVALIBLE, statm.nodes[i] );

				break;
		}
	}
	return 0;
}



int master_done(void)
{
	//TODO: query input, etc
	return 0;
}

