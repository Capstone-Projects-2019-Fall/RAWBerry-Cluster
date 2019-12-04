/*
 * ============================================================================
 *
 *       Filename:  cluster.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2019 12:25:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Gruda, tuh37025@temple.edu
 *
 * ============================================================================
 */
#define _BSD_SOURCE
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

#include "cluster.h"
#include "util.h"

int this_node_rank;
int num_nodes;
char hostname[256];

FILE* _mtrf;

void exit_mpi(void)
{
	fflush(_mtrf);
	fclose(_mtrf);
	MPI_Finalize();
	exit(0);
}

int init_mpi(int argc, char **argv)
{
	int err, sup, i = 0;
	gethostname(hostname, sizeof(hostname));
	err = MPI_Init_thread(&argc, &argv, MPI_THREAD_FUNNELED, &sup);
	if(err != MPI_SUCCESS || sup < MPI_THREAD_FUNNELED){
		fprintf(stderr, "Cannot initialize MPI\n");
		return -1;
	}
	MPI_Comm_size(MPI_COMM_WORLD, &num_nodes);
	if(num_nodes <= 2){
		fprintf(stderr, "RAWBerry must be run with at least 3 nodes\n");
		return -2;
	}
	MPI_Comm_rank(MPI_COMM_WORLD, &this_node_rank);
	VLOGF("Proc %d, rank %d, on %s\n", getpid(), this_node_rank, hostname);
	return 0;
}

int cluster(struct cluster_args *params)
{
	int  ret;
	char *mfname;
	if(this_node_rank == NODE_MASTER){
		asprintf(&mfname, "%s/master.log", params->log_dir);
		_mtrf = fopen(mfname, "w+");
		ret = master(params, num_nodes - 2);
	}else if(this_node_rank == NODE_COLLECTOR){
		asprintf(&mfname, "%s/collector.log", params->log_dir);
		_mtrf = fopen(mfname, "w+");
		ret = collector(params);
	}else{
		asprintf(&mfname, "%s/slave-%d.log", params->log_dir, this_node_rank - 2);
		_mtrf = fopen(mfname, "w+");
		ret = slave(params);
	}
	return ret;
}

int nb_waitany(int len, MPI_Request *reqs, int *i, MPI_Status *stat)
{
	int r, v;
	do{
		r = MPI_Testany(len, reqs, i, &v, stat);
		usleep(1000);
	}while(!v);
	return r;
}

int nb_probe(int source, int tag, MPI_Comm comm, MPI_Status *stat)
{
	int i = 0, r = 0;
	do{
		r = MPI_Iprobe(source, tag, comm, &i, stat);
		usleep(1000);
	}while(!i);
	return r;
}

void c_bcast_send(struct reply *r)
{
	MPI_Request *rp = malloc(sizeof(MPI_Request) * (num_nodes - 1));
	int i = 0, j = 0;
	for(; i < num_nodes; i++){
		if(i != this_node_rank){
			*(rp + j) = MPI_REQUEST_NULL;
			MPI_Isend(r, sizeof(struct reply), MPI_BYTE, i, TAG_B_ALRT, 
				MPI_COMM_WORLD,  rp + j);
			j++;
		}
	}
	i = MPI_Waitall(j, rp, MPI_STATUS_IGNORE);
	if(i != MPI_SUCCESS){
		exit(-3);
	}
}

void c_bcast_irecv(struct reply *msg, MPI_Request *r)
{
	MPI_Irecv(msg, sizeof(struct reply), MPI_BYTE, MPI_ANY_SOURCE, TAG_B_ALRT, 
			MPI_COMM_WORLD, r);
}

void c_bcast_wait_exit(void)
{
	MPI_Request r;
	struct reply rp;
	do{
		c_bcast_irecv(&rp, &r);
		MPI_Wait(&r, MPI_STATUS_IGNORE);
	}while(rp.message != REPLY_MSG_EXIT);
	exit_mpi();
}
