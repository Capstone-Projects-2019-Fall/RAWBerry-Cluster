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

#define ACTION_SRECV
#define ACTION_SSEND

struct status_m{
	MPI_Request *reqs;
	int *actions;
	int *nodes;
	void **data;
	int mvals;
};

void _init_status(struct status_m *s, int mvals)
{
	s->mvals = mvals;
	s->reqs = calloc(sizeof(MPI_Request), s->mvals);
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

int _wait_status(struct status_m *s)
{
	int i; 
	MPI_Status s;
	MPI_Waitany(s->mvals, s->reqs, &i,  &s);
	return i;
}

int master(struct cluster_args *params, int slaves)
{
	buf_handle_t buf;
	int status, i, c;
	void *frame;
	struct status_m statm;
	_init_status(&statm, slaves * 2 + 2);
	status = init_input(params, &buf);
	for(i = 0; i < slaves; i++){
		c = _create_resp(&m, ACTION_SRECV, 2 + i);
		MPI_Irecv(&(statm.data[c]), 2, MPI_INT, i + 2, TAG_S_RET,
			MPI_COMM_WORLD, &(statm.reqs[c]));
	}

	while(!master_done()){
		i = _wait_status(&statm);	
	}

}

int master_done(void)
{
	//TODO: query input, etc
	return 0;
}

