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
#include "util.h"

#define A_FRAME_AVALIBLE 1
#define A_FRAMETX_DONE   2
#define A_BCAST_RECV 	 3

static int nslaves;
static MPI_Request *reqs;
static void **datas;

static int _coll_select(MPI_Status *s, int *action)
{
	int er = 0, idx, flag;
       /* er = MPI_Testany(nslaves, reqs, &idx, &flag, s);*/
	/*if(flag){*/
		/**action = A_FRAMETX_DONE;*/
		/*return er;*/
	/*}*/
	er = nb_probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, s);
	if(s->MPI_TAG == TAG_S_TO){
		*action = A_FRAME_AVALIBLE;
	}else if(s->MPI_TAG == TAG_B_ALRT){
		*action = A_BCAST_RECV;
	}
	return er;
}

int _coll_recv_frame(MPI_Status *s, void **frame, int *sz)
{
	int errc;
	errc = MPI_Get_count(s, MPI_BYTE, sz);
	if(errc != MPI_SUCCESS) {}
	*frame = malloc(sizeof(uint8_t) * (*sz));
	errc = MPI_Recv(*frame, *sz, MPI_BYTE, s->MPI_SOURCE, s->MPI_TAG, 
			MPI_COMM_WORLD, s);
	return errc;
}

void _coll_stream_frame(void *frame, int sz)
{
	/* TODO: Connect with streaming server
	get msec somehow?
	streamFrame(frame, sz, msec);
	 */
	tprintf("%s: %d\n", ((char*)frame)+4, *(int*)frame);
}

int collector_done(void)
{
	return 0;
}

int collector(struct cluster_args *args)
{
	int errc, i, sz;
	void *cframe;
	MPI_Status stat;
	nslaves = num_nodes - NSLAVE_START;
	reqs = malloc(sizeof(MPI_Request) * nslaves);
	for(i = 0; i < nslaves; i++){
		*(reqs + i) = MPI_REQUEST_NULL;
	}
	errc = init_stream_server(args);
	
	while(!collector_done()){
		errc = _coll_select(&stat, &i);
		if(errc != MPI_SUCCESS){
			//TODO:Error handle
		}
		/*tprintf("Collector action: %d\n", i);*/
		switch(i){
			case A_FRAME_AVALIBLE:
				_coll_recv_frame(&stat, &cframe, &sz);
				_coll_stream_frame(cframe, sz);
				break;
			case A_BCAST_RECV:
				break;
		}

	}
	return 0;
}
