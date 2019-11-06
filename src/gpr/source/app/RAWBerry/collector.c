/*
 * =============================================================================
 *
 *       Filename:  collector.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/19/2019 07:28:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Gruda (mg), matthewgruda@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include <stdlib.h>
#include <mpi.h>

#include "cluster.h"

#define A_FRAME_AVALIBLE 1
#define A_FRAMETX_DONE   2
#define A_BCAST_RECV 	 3

static int nslaves;
static MPI_Request *reqs;
static void **datas;

static int _coll_select(MPI_Status *s, int *action)
{
	int er = 0, idx, flag;
	er = MPI_Testany(nslaves, reqs, &idx, &flag, s);
	if(flag){
		*action = A_FRAMETX_DONE;
		return er;
	}
	er = MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, s);
	if(s->MPI_TAG == TAG_S_TO){
		*action = A_FRAMETX_DONE;
	}else if(s->MPI_TAG == TAG_B_ALRT){
		*action = A_BCAST_RECV;
	}
	return er;
}

int _coll_recv_frame(MPI_Status *s)
{
	
}

int collector(struct cluster_args *args)
{
	int errc, i;
	MPI_Status stat;
	nslaves = num_nodes - NSLAVE_START;
	reqs = malloc(sizeof(MPI_Request) * nslaves);
	for(i = 0; i < nslaves; i++){
		*(reqs + i) = MPI_REQUEST_NULL;
	}
	//errc = init_stream_server(args);
	
	while(true){//!collector_done()){
		errc = _coll_select(&stat, &i);
		if(errc != MPI_SUCCESS){
			//TODO:Error handle
		}
		switch(i){
			case A_FRAME_AVALIBLE:
				//_coll_recv_frame(&stat);
				break;
			case A_FRAMETX_DONE:
				//_coll_send_frame(&stat);
				break;
		}

	}
	return 0;
}
