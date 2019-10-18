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

struct slave_m{
	MPI_Request in;
	MPI_Request reply;
	MPI_Request send;
	MPI_Request bcast;
};

#define RPSZ 16

static struct reply rpool[RPSZ];
static int rpidx;

void _slave_reply(struct slave_m *s, uint32_t framenum)
{
	struct reply *r = rpool + (rpidx % RPSZ);
	strcpy(r, REPLY_MSG_SUCCESS);
	r->plod = framenum;
}

int slave(struct cluster_args *params)
{

	while(!slave_done()){
		
	}
	return 0;
}

int slave_done(void)
{
	return 0;
}
