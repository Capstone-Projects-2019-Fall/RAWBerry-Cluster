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

#include "util.h"
#include "sopool.h"
#include "gpr.h"

#define ACTION_SLAVE_AVALIBLE 1
#define ACTION_SLAVE_SENT 2
#define ACTION_SLAVE_SENTP 3
#define ACTION_BCAST_RECV 4

static struct{
	MPI_Request *reqs;
	int *actions;
	int *nodes;
	void **data;
	void **d2;
	int mvals;
} mstat;

static buf_handle_t _in;
static int _fn = 0;

static struct sopool reply_pool;

static void _init_status(int mvals)
{
	int i = 0;
	mstat.mvals = mvals;
	mstat.reqs = calloc(sizeof(MPI_Request), mstat.mvals);
	for(; i < mvals; i++){
		*(mstat.reqs + i) = MPI_REQUEST_NULL;
	}
	mstat.actions = calloc(sizeof(int), mstat.mvals);
	mstat.nodes = calloc(sizeof(int), mstat.mvals);
	mstat.data = malloc(sizeof(void *) * mstat.mvals);
	mstat.d2 = malloc(sizeof(void *) * mstat.mvals);
}

static int _create_resp(int action, int node)
{
	int i = 0;
	while((*(mstat.reqs + i) != MPI_REQUEST_NULL) && i < mstat.mvals)
		i++;
	*(mstat.actions + i) = action;
	*(mstat.nodes + i) = node;
	return i;
}

static int _wait_status(int *errc)
{
	int i; 
	MPI_Status stat;
	*errc = MPI_Waitany(mstat.mvals, mstat.reqs, &i,  &stat);
	if(i < 0){
		return -1;
	}
	*(mstat.reqs + i) = MPI_REQUEST_NULL;
	return i;
}

static void _send_params(int to, struct raw_prefix *out, void *fr)
{
	int c, err;
	c = _create_resp(ACTION_SLAVE_SENTP, to);
	err = MPI_Isend(out, sizeof(struct raw_prefix), MPI_BYTE, to, TAG_S_TO, 
			MPI_COMM_WORLD, mstat.reqs + c);
	*(mstat.data + c) = out;
	*(mstat.d2 + c) = fr;
	if(err != MPI_SUCCESS){

	}
}
static void _send_frame(int to, void *frame, int size)
{
	int c, err;
	c = _create_resp(ACTION_SLAVE_SENT, to);
	err = MPI_Isend(frame, size, MPI_BYTE, to, TAG_S_TO, 
			MPI_COMM_WORLD, mstat.reqs + c);
	*(mstat.data + c) = frame;
	if(err != MPI_SUCCESS){

	}
}

static void _irecv_reply(int action, int node)
{
	int c = _create_resp(action, node);
	struct reply *r = sopool_get_new(&reply_pool);
	mstat.data[c] = r;
	MPI_Irecv(r, sizeof(struct reply), MPI_BYTE, node, TAG_S_RET,
			MPI_COMM_WORLD, &(mstat.reqs[c]));
}

static void _master_bcast_recv()
{
	int c = _create_resp(ACTION_BCAST_RECV, 0);
	struct reply *r = sopool_get_new(&reply_pool);
	mstat.data[c] = r;
	MPI_Irecv(r, sizeof(struct reply), MPI_BYTE, MPI_ANY_SOURCE, TAG_B_ALRT,
			MPI_COMM_WORLD, &(mstat.reqs[c]));
}


static int _master_get_frame(void **frame, struct raw_prefix **params)
{
	int i = get_frame(frame, params);
	if(i == 1){
		VLOGF("Exiting on frame %d\n", _fn - 1);
		struct reply *r = sopool_get_new(&reply_pool);
		r->message = REPLY_MSG_LFRAME;
		r->payload = _fn - 1;
		c_bcast_send(r);
		return 1;
	}
	VLOGF("Getting frame %d\n", _fn);
	_fn++;
	return 0;
}

int master(struct cluster_args *params_, int slaves)
{
	int si = 0, i = 0, c = 0;
	int j = 0;
	int errorc = 0;
	int exit_req = 0;
	int tx_in_progress = 0;
	struct raw_prefix *params, *ptmp;
	void *frame = NULL, *tmp;
	sopool_init(&reply_pool, sizeof(struct reply), slaves, 0);
	_init_status(slaves * 2 + 2);
	si = init_input(params_, &_in);
	_master_get_frame(&frame, &params);

	for(i = 0; i < slaves; i++){
		_irecv_reply(ACTION_SLAVE_AVALIBLE, 2 + i);
	}
	while(1){
		i = _wait_status(&errorc);	
		if(errorc != MPI_SUCCESS){
			//TODO:ERROR HANDLER
		}
		if(i == -1){
			return 0;
		}
		switch(mstat.actions[i]){
			case ACTION_SLAVE_AVALIBLE:
				sopool_return(&reply_pool, mstat.data[i]);
				_send_params(mstat.nodes[i], params, frame); 
				tx_in_progress++;
				if(!exit_req)
					exit_req = _master_get_frame(&frame, &params);
				break;
			case ACTION_SLAVE_SENT:
				tmp = mstat.data[i];
				free(tmp);
				_irecv_reply(ACTION_SLAVE_AVALIBLE, mstat.nodes[i]);
				tx_in_progress--;
				if(exit_req && !tx_in_progress){
					VLOGF("master waiting for exit\n");
					c_bcast_wait_exit();
					exit_mpi();
				}
				break;
			case ACTION_SLAVE_SENTP:
				ptmp = mstat.data[i];
				_send_frame(mstat.nodes[i], mstat.d2[i],
					ptmp->size);
				free(ptmp);
				break;
			case ACTION_BCAST_RECV:

				break;
			default:
				fprintf(stderr, "Bad action code %d, on %d\n",
						mstat.actions[i], i);
				exit(-1);
		}
	}
	return 0;
}


