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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

#include "cluster.h"
#include "util.h"

int this_node_rank;
int num_nodes;
char hostname[256];

void exit_mpi(void)
{
	MPI_Finalize();
	exit(-1);
}

int init_mpi(void)
{
	int err, sup, i = 0;
	gethostname(hostname, sizeof(hostname));
	err = MPI_Init_thread(NULL, NULL, MPI_THREAD_FUNNELED, &sup);
	if(err != MPI_SUCCESS || sup < MPI_THREAD_FUNNELED){
		fprintf(stderr, "Cannot initialize MPI\n");
		return -1;
	}
	MPI_Comm_size(MPI_COMM_WORLD, &num_nodes);
	if(num_nodes <= 2){
		fprintf(stderr, 
			"This program must be run with at least 3 nodes.");
		return -2;
	}
	MPI_Comm_rank(MPI_COMM_WORLD, &this_node_rank);
	tprintf("Proc %d, rank %d, on %s\n", getpid(), this_node_rank, hostname);
	return 0;
}

int cluster(struct cluster_args *params)
{
	int  ret;
	if(this_node_rank == NODE_MASTER){
		ret = master(params, num_nodes - 2);
	}else if(this_node_rank == NODE_COLLECTOR){
		ret = collector(params);
	}else{
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

