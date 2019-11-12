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

#define ACTION_FRAME_GET 	1
#define ACTION_REPLY_DONE 	2
#define ACTION_SEND_DONE 	3
#define ACTION_BCAST_ALRT 	4

struct slave_m{
	union{ 
		struct{ 
			MPI_Request in;
			MPI_Request reply;
			MPI_Request send;
			MPI_Request bcast;
		};
		MPI_Request arr[4];
	};
};

static int actions[] = { ACTION_FRAME_GET, ACTION_REPLY_DONE, ACTION_SEND_DONE,
	ACTION_BCAST_ALRT };
static void *datas[4] = {NULL, NULL, NULL, NULL};

static struct sopool reply_pool;

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
		exit(0);
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


static void _recv_frame(void **frame, gpr_parameters *p)
{
	MPI_Irecv(p, sizeof(gpr_parameters), MPI_BYTE, NODE_MASTER, TAG_S_TO, MPI_COMM_WORLD,
			SCREQ);
	_slave_bwait();
	*frame = malloc(p->preview_image.preview_width);
	MPI_Irecv(*frame, p->preview_image.preview_width, MPI_BYTE, NODE_MASTER, TAG_S_TO, 
		MPI_COMM_WORLD, SCREQ);
	_slave_bwait();
}

static void _send_cframe(void *cframe, int sz)
{
	int errc = 0;
	fprintf(stderr, "Sending frame\n");
	errc = MPI_Isend(cframe, sz, MPI_BYTE, NODE_COLLECTOR, TAG_S_TO, 
		MPI_COMM_WORLD, SCREQ);
	_slave_bwait();
	if(errc != MPI_SUCCESS){
		//TODO:Error handle
	}
}

static int _s_compress(void *in, gpr_parameters *p, void **out, int *sz)
{
	int fnum = p->preview_image.preview_height;
	printf("Compressing frame %d\n", fnum);
	encode(in, p, out, sz);
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
	gpr_parameters p;
	init_engine(params);
	MPI_Irecv(&_rbcast, sizeof(struct reply), MPI_BYTE, MPI_ANY_SOURCE, 
				TAG_B_ALRT, MPI_COMM_WORLD, &_slave_ctl.bcast);
	_slave_reply_scs(0);
	while(!slave_done()){
		_recv_frame(&frame_in, &p);
		fnum = _s_compress(frame_in, &p, &frame_out, &sz);
		_send_cframe(frame_out, sz);
		_slave_reply_scs(fnum);
	}
	return 0;
}

int slave_done(void)
{
	return 0;
}
