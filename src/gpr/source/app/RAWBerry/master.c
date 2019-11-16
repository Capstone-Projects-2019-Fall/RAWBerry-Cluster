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

struct status_m{
	MPI_Request *reqs;
	int *actions;
	int *nodes;
	void **data;
	void **d2;
	int mvals;
};

static buf_handle_t _in;
static int _fn = 0;
static int sz = sizeof(gpr_parameters);

static struct sopool frame_pool;
static struct sopool reply_pool;

#ifndef TEST


# ifdef UNUSED
int get_frame(void **frame)
{
	int res = 0;
	if(!buf_empty(_in)){
		res = buf_get(_in, *frame);
	}
	return res;
}
# endif 
#endif  // NDEF TEST 

void _init_status(struct status_m *s, int mvals)
{
	int i = 0;
	s->mvals = mvals;
	s->reqs = calloc(sizeof(MPI_Request), s->mvals);
	for(; i < mvals; i++){
		*(s->reqs + i) = MPI_REQUEST_NULL;
	}
	s->actions = calloc(sizeof(int), s->mvals);
	s->nodes = calloc(sizeof(int), s->mvals);
	s->data = malloc(sizeof(void *) * s->mvals);
	s->d2 = malloc(sizeof(void *) * s->mvals);
}

int _create_resp(struct status_m *s, int action, int node)
{
	int i = 0;
	while((*(s->reqs + i) != MPI_REQUEST_NULL) && i < s->mvals)
		i++;
	*(s->actions + i) = action;
	*(s->nodes + i) = node;
	return i;
}

int _wait_status(struct status_m *s, int *errc)
{
	int i; 
	MPI_Status stat;
	*errc = MPI_Waitany(s->mvals, s->reqs, &i,  &stat);
	if(i < 0){
		return -1;
	}
	*(s->reqs + i) = MPI_REQUEST_NULL;
	return i;
}

void _send_params(struct status_m *s, int to, struct raw_prefix *out, void *fr)
{
	int c, err;
	c = _create_resp(s, ACTION_SLAVE_SENTP, to);
	err = MPI_Isend(out, sizeof(struct raw_prefix), MPI_BYTE, to, TAG_S_TO, 
			MPI_COMM_WORLD, s->reqs + c);
	*(s->data + c) = out;
	*(s->d2 + c) = fr;
	if(err != MPI_SUCCESS){

	}
}
void _send_frame(struct status_m *s, int to, void *frame, int size)
{
	int c, err;
	c = _create_resp(s, ACTION_SLAVE_SENT, to);
	err = MPI_Isend(frame, size, MPI_BYTE, to, TAG_S_TO, 
			MPI_COMM_WORLD, s->reqs + c);
	*(s->data + c) = frame;
	if(err != MPI_SUCCESS){

	}
}

void _irecv_reply(struct status_m *s, int action, int node)
{
	int c = _create_resp(s, action, node);
	struct reply *r = sopool_get_new(&reply_pool);
	s->data[c] = r;
	MPI_Irecv(r, sizeof(struct reply), MPI_BYTE, node, TAG_S_RET,
			MPI_COMM_WORLD, &(s->reqs[c]));
}

static void _master_bcast_recv(struct status_m *s)
{
	int c = _create_resp(s, ACTION_BCAST_RECV, 0);
	struct reply *r = sopool_get_new(&reply_pool);
	s->data[c] = r;
	MPI_Irecv(r, sizeof(struct reply), MPI_BYTE, MPI_ANY_SOURCE, TAG_B_ALRT,
			MPI_COMM_WORLD, &(s->reqs[c]));
}


static int _master_get_frame(void **frame, struct raw_params **params)
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
	struct status_m statm;
	struct raw_prefix *params, *ptmp;
	void *frame = NULL, *tmp;
	sopool_init(&reply_pool, sizeof(struct reply), slaves, 0);
	_init_status(&statm, slaves * 2 + 2);
	si = init_input(params_, &_in);
	_master_get_frame(&frame, &params);

	for(i = 0; i < slaves; i++){
		_irecv_reply(&statm, ACTION_SLAVE_AVALIBLE, 2 + i);
	}
	while(!master_done()){
		i = _wait_status(&statm, &errorc);	
		if(errorc != MPI_SUCCESS){
			//TODO:ERROR HANDLER
		}
		if(i == -1){
			return 0;
		}
		switch(statm.actions[i]){
			case ACTION_SLAVE_AVALIBLE:
				sopool_return(&reply_pool, statm.data[i]);
				_send_params(&statm, statm.nodes[i], params, frame); 
				tx_in_progress++;
				if(!exit_req)
					exit_req = _master_get_frame(&frame, &params);
				break;
			case ACTION_SLAVE_SENT:
				tmp = statm.data[i];
				free(tmp);
				_irecv_reply(&statm, ACTION_SLAVE_AVALIBLE, statm.nodes[i] );
				tx_in_progress--;
				if(exit_req && !tx_in_progress){
					VLOGF("master waiting for exit\n");
					c_bcast_wait_exit();
					exit_mpi();
				}
				break;
			case ACTION_SLAVE_SENTP:
				ptmp = statm.data[i];
				_send_frame(&statm, statm.nodes[i], statm.d2[i],
					ptmp->size);
				free(ptmp);
				break;
			case ACTION_BCAST_RECV:

				break;
			default:
				fprintf(stderr, "Bad action code %d, on %d\n",
						statm.actions[i], i);
				exit(-1);
		}
	}
	return 0;
}



int master_done(void)
{
	//TODO: query input, etc
	return 0;
}

