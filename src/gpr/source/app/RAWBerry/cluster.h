/*
 * ============================================================================
 *
 *       Filename:  cluster.h
 *
 *    Description:  Definitions for the data-path layer of the RAWBerry cluster 
 *
 *        Version:  1.0
 *        Created:  10/17/2019 12:03:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Gruda, tuh37025@temple.edu
 *
 * ============================================================================
 */


#ifndef  cluster_INC
#define  cluster_INC

#include <stdbool.h>

#include "buffer.h"
#include "gpr.h"

#define NODE_MASTER 0
#define NODE_COLLECTOR 1
#define NSLAVE_START   2
#define TAG_S_RET 1
#define TAG_S_TO  2
#define TAG_B_ALRT 3

#ifndef TEST
#define FRAME_RAW_SIZEB _frame_size
#else 
#define FRAME_RAW_SIZEB 40
#endif


struct cluster_args{
	char *in_dir;
	char *out_dir;
	char *rtsp_loc;
	bool verbose;
	bool use_rtsp;
	//TODO: add additional ops as needed 
};

struct raw_prefix{
	gpr_parameters params;
	int size;
	int framenum;
};

struct reply{
	uint8_t  message;
	uint8_t  padding[3];
	int32_t payload;
};

#define REPLY_MSG_SUCCESS  0x01
#define REPLY_MSG_LFRAME     0x02
#define REPLY_MSG_EXIT	    0x03

extern int this_node_rank;
extern int num_nodes;
extern int _frame_size;

int init_mpi(int argc, char **argv);
void exit_mpi(void);

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  parse_args
 *  Description:  
 * ============================================================================
 */
struct cluster_args *parse_args(int argc, char *argv);


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  cluster
 *  Description:  cluster entry point
 * ============================================================================
 */
int cluster(struct cluster_args *params);

//Master node funcs

int master(struct cluster_args *params, int slaves);
int init_input(struct cluster_args *params, buf_handle_t *buf);
int get_frame(void **frame, struct raw_prefix **params);
int master_done(void);

//Slave node funcs

int slave(struct cluster_args *params);
int init_engine(struct cluster_args *params);
int encode(void *in, gpr_parameters *p, int insize, void **out, int *sz);
int slave_done(void);

//collector node funcs

int collector(struct cluster_args *args);
int collector_done(void);
void stream_frame(void *frame, int sz, int frnum);
int init_stream_server(struct cluster_args *args);

extern bool verbose;

#define VLOGF(A, ...) if(verbose) { fprintf(stderr, A, ##__VA_ARGS__); }

#ifndef NMPI
#include <mpi.h>
int nb_probe(int source, int tag, MPI_Comm comm, MPI_Status *stat);
int nb_waitany(int len, MPI_Request *reqs, int *i, MPI_Status *stat);
void c_bcast_send(struct reply *r);
void c_bcast_irecv(struct reply *msg, MPI_Request *r);
void c_bcast_wait_exit(void);
#endif

#endif   /* ----- #ifndef cluster_INC  ----- */

