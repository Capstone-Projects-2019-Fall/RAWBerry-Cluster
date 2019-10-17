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

#include <stdlib.h>
#include <mpi.h>

#include "cluster.h"

int cluster(struct cluster_args *params)
{
	int id, nodes, ret;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &nodes);
	if(nodes <= 2){
		fprintf(stderr, 
			"This program must be run with at least 3 nodes.");
		exit(-1);
	}
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	if(id == NODE_MASTER){
		ret = master(params, nodes - 2);
	}else if(id == NODE_COLLECTOR){
		ret = collector(params);
	}else{
		ret = slave(params);
	}
	return ret;
}



