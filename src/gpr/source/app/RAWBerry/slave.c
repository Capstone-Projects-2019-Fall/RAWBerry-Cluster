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
#include "util.h"
#include "sopool.h"
#include "gpr.h"

static struct reply _rcur, _rbcast;

static struct{
	union{
		struct{
			MPI_Request creq;
			MPI_Request bcast;
		};
		MPI_Request arr[2];
	};
} _slave_ctl;


static void _slave_h_bcast()
{
	if(_rbcast.message == REPLY_MSG_EXIT){
		exit_mpi();
	}else{
		MPI_Irecv(&_rbcast, sizeof(struct reply), MPI_BYTE, MPI_ANY_SOURCE, 
				TAG_B_ALRT, MPI_COMM_WORLD, &_slave_ctl.bcast);
	}
}

static void _slave_bwait()
{
	MPI_Status stat;
	int i, errc;
	while((errc = MPI_Waitany(2, _slave_ctl.arr, &i, &stat)) == MPI_SUCCESS){
		if(i == 0){
			return;
		}else if(i == 1){
			_slave_h_bcast();
			continue;
		}else{
			fprintf(stderr, "Error in _slave_bwait: bad index\n");
		}
	}
}

#define SCREQ &(_slave_ctl.creq)

void _slave_reply_scs(int32_t framenum)
{
	_rcur.message = REPLY_MSG_SUCCESS;
	_rcur.payload = framenum;
	MPI_Isend(&_rcur, sizeof(struct reply), MPI_BYTE, NODE_MASTER,  TAG_S_RET,
			MPI_COMM_WORLD, SCREQ);  
	_slave_bwait();
}


static void _recv_frame(void **frame, struct raw_prefix *p)
{
	MPI_Irecv(p, sizeof(struct raw_prefix), MPI_BYTE, NODE_MASTER, TAG_S_TO, MPI_COMM_WORLD,
			SCREQ);
	_slave_bwait();
	*frame = malloc(p->size);
	MPI_Irecv(*frame, p->size, MPI_BYTE, NODE_MASTER, TAG_S_TO, 
		MPI_COMM_WORLD, SCREQ);
	_slave_bwait();
}

static void _send_cframe(void *cframe, int sz)
{
	int errc = 0;
	VLOGF("Sending frame\n");
	errc = MPI_Isend(cframe, sz, MPI_BYTE, NODE_COLLECTOR, TAG_S_TO, 
		MPI_COMM_WORLD, SCREQ);
	_slave_bwait();
	if(errc != MPI_SUCCESS){
		//TODO:Error handle
	}
}

static int _s_compress(void *in, struct raw_prefix *p, void **out, int *sz)
{
	int fnum = p->framenum;
	VLOGF("Compressing frame %d\n", fnum);
	encode(in, &(p->params), p->size, out, sz);
	free(in);
	*out = realloc(*out, *sz + 4);
	memcpy((uint8_t *)*out + 4, *out, *sz);
	*(int *)*out = fnum;
	*sz += 4;
	return fnum;
}

int slave(struct cluster_args *params)
{
	int sz = 0, fnum = 0;
	void *frame_in = NULL;
	void *frame_out = NULL;
	struct raw_prefix p;
	init_engine(params);
	MPI_Irecv(&_rbcast, sizeof(struct reply), MPI_BYTE, MPI_ANY_SOURCE, 
				TAG_B_ALRT, MPI_COMM_WORLD, &_slave_ctl.bcast);
	_slave_reply_scs(0);
	while(1){
		_recv_frame(&frame_in, &p);
		fnum = _s_compress(frame_in, &p, &frame_out, &sz);
		_send_cframe(frame_out, sz);
		_slave_reply_scs(fnum);
	}
	return 0;
}

