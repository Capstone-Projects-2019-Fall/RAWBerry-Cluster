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
#include "cluster.h"

#include "util.h"
#include "sopool.h"

#define ACTION_SLAVE_AVALIBLE 1
#define ACTION_SLAVE_SENT 2

struct status_m{
	MPI_Request *reqs;
	int *actions;
	int *nodes;
	void **data;
	int mvals;
};

static buf_handle_t _in;
static int _fn = 0;

static struct sopool frame_pool;
static struct sopool reply_pool;

#ifndef TEST

int get_frame(void **frame)
{
	int res = 0;
	if(!buf_empty(_in)){
		res = buf_get(_in, *frame);
	}
	return res;
}

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
	while((*(s->reqs + i) == MPI_REQUEST_NULL) && i < s->mvals)
		i++;
	*(s->actions + i) = action;
	*(s->nodes + i) = node;
	return i;
}

int _wait_status(struct status_m *s, int *errc)
{
	int i; 
	MPI_Status stat;
	*errc = MPI_Waitany(s->mvals, s->reqs, &i,  &stat);
	*(s->reqs + i) = MPI_REQUEST_NULL;
	return i;
}

void _send_frame(struct status_m *s, int to, void *frame)
{
	int c, err;
	c = _create_resp(s, ACTION_SLAVE_SENT, to);
	err = MPI_Isend(frame, FRAME_RAW_SIZEB, MPI_BYTE, to, TAG_S_TO, 
			MPI_COMM_WORLD, s->reqs + c);
	*(s->data + c) = frame;
	if(err != MPI_SUCCESS){

	}
}

int master(struct cluster_args *params, int slaves)
{
	int si = 0, i = 0, c = 0;
	int errorc = 0;
	struct status_m statm;
	void *frame, *tmp;

	sopool_init(&frame_pool, FRAME_RAW_SIZEB, 3, SOPOOL_HINT_GROW_1);
	sopool_init(&reply_pool, sizeof(struct reply), slaves, 0);
	frame = sopool_get_new(&frame_pool);
	_init_status(&statm, slaves * 2 + 2);
	si = init_input(params, &_in);
	for(i = 0; i < slaves; i++){
		c = _create_resp(&statm, ACTION_SLAVE_AVALIBLE, 2 + i);
		MPI_Irecv(&(statm.data[c]), 2, MPI_INT, i + 2, TAG_S_RET,
			MPI_COMM_WORLD, &(statm.reqs[c]));
	}
	get_frame(&frame);
	while(!master_done()){
		i = _wait_status(&statm, &errorc);	
		if(errorc != MPI_SUCCESS){
			//TODO:ERROR HANDLER
		}
		switch(statm.actions[i]){
			case ACTION_SLAVE_AVALIBLE:
				_send_frame(&statm, statm.nodes[i], frame); 
				frame = sopool_get_new(&frame_pool);
				get_frame(&frame);
				break;
			case ACTION_SLAVE_SENT:
				tmp = statm.data[i];
				sopool_return(&frame_pool, tmp);
				c = _create_resp(&statm, ACTION_SLAVE_AVALIBLE,
					2 + i);
				MPI_Irecv(&(statm.data[c]), 2, MPI_INT, 
					i + 2, TAG_S_RET, MPI_COMM_WORLD, 
					&(statm.reqs[c]));
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

