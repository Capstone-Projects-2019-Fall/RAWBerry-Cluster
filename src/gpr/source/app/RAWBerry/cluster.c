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
#include <mpi.h>

#include "cluster.h"

int this_node_rank;
int num_nodes;

int init_mpi(void)
{
	int err, sup;
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



