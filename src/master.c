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

struct status_m{
	MPI_Request *reqs;
	int *actions;
	int *nodes;
	int vals;
	int mvals;
};

void _init_status(struct status_m *s, int slaves)
{
	s->mvals = slaves * 2 + 2;
	s->vals = 0;
	s->reqs = calloc(sizeof(MPI_Request), s->mvals);
	s->actions = calloc(sizeof(int), s->mvals);
	s->nodes = calloc(sizeof(int), s->mvals);
}

int master(struct cluster_args *params, int slaves)
{
	buf_handle_t buf;
	int status;
	void *frame;
	struct status_m statm;
	statm.vals = 0;
	statm.mvals = 
	 = malloc(sizeof(MPI_Request) * (slaves * 2 + 2));
	status = init_input(params, &buf);

	while(!master_done()){
		
	}

}

int master_done(void)
{
	//TODO: query input, etc
	return 0;
}

