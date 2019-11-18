/*
 * ============================================================================
 *
 *       Filename:  cluster.h
 *
 *    Description:  Definitions for the data-path layer of the RAWBerry cluster 
 *    		    The data path is composed of three types of nodes:
 *    		    	master, slave, collector.
 *    		    Each is defined in their own file, and has another file
 *    		     where the interface beween the data-path and their module
 *    		     is defined.
 *    		    Plus general support functions in cluster.c
 *		    master - frame input, slave coordination
 *		    slave - frame compression
 *		    collector - frames sent to output
 *
 *		    The flow of frames is thus master -> slave -> collector
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

//Node ranks
#define NODE_MASTER 0
#define NODE_COLLECTOR 1
#define NSLAVE_START   2
//Message tags
#define TAG_S_RET 1
#define TAG_S_TO  2
#define TAG_B_ALRT 3

/*
 * Commandline params + defaults
 */
struct cluster_args{
	char *in_dir;
	char *out_dir;
	char *rtsp_loc;
	bool verbose;
	bool use_rtsp;
	//TODO: add additional ops as needed 
};

/*
 * Sent before a frame.
 */
struct raw_prefix{
	gpr_parameters params;
	int size;
	int framenum;
};

/*
 * For sending messages within cluster
 */
struct reply{
	uint8_t  message;
	uint8_t  padding[3];
	int32_t payload;
};

#define REPLY_MSG_SUCCESS  0x01
#define REPLY_MSG_LFRAME     0x02
#define REPLY_MSG_EXIT	    0x03

/*
 * this_node_rank, num_nodes - globals, treat as write only.
 * located in cluster.c
 */
extern int this_node_rank;
extern int num_nodes;


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  init_mpi
 *  Description:  Starts MPI. argc, argv - from main
 * ============================================================================
 */
int init_mpi(int argc, char **argv);

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  exit_mpi
 *  Description:  Finallizes MPI and exit(0). Must be called to exit with 0,
 *  		for non-0 exits, regular exit(errc) is ok.
 * ============================================================================
 */
void exit_mpi(void);

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  cluster
 *  Description:  cluster entry point
 * ============================================================================
 */
int cluster(struct cluster_args *params);

//Master node funcs
// master.c: master data-path
// input.c:  input api defined
/* 
 * ===  FUNCTION  =============================================================
 *         Name:  master
 *  Description:  master entry point
 * ============================================================================
 */
int master(struct cluster_args *params, int slaves);

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  init_input
 *  Description:  called from master - entry point for 
 *  		input module setup.
 *  		buf - to be for buffer, but unused
 * ============================================================================
 */
int init_input(struct cluster_args *params, buf_handle_t *buf);

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  get_frame
 *  Description:  Called from master, puts the next frame and corresponding
 *  		params in *frame, *params.  These will be freed 
 *  		by the calling function
 * ============================================================================
 */
int get_frame(void **frame, struct raw_prefix **params);

//Slave node funcs
// slave.c: slave data-path
// encode.c: encoder api defined
/* 
 * ===  FUNCTION  =============================================================
 *         Name:  slave
 *  Description:  slave node entry point
 * ============================================================================
 */
int slave(struct cluster_args *params);

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  init_engine
 *  Description:  init for compression engine - currently unused
 * ============================================================================
 */
int init_engine(struct cluster_args *params);

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  encode
 *  Description:  Takes in of insize, parameters p, returns *out of *sz.
 *  		Compresses a frame.  *out is owned by caller.
 * ============================================================================
 */
int encode(void *in, gpr_parameters *p, int insize, void **out, int *sz);

//collector node funcs
// data-path of collector is in collector.c
// server.c for streaming portion
/* 
 * ===  FUNCTION  =============================================================
 *         Name:  collector
 *  Description:  collector node entry point
 * ============================================================================
 */
int collector(struct cluster_args *args);

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  stream_frame
 *  Description:  Called to send a frame to streaming server.
 *  		frame is sz bytes, for frnum
 * ============================================================================
 */
void stream_frame(void *frame, int sz, int frnum);

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  init_stream_server
 *  Description:  called to startup rtsp server or fileoutput
 * ============================================================================
 */
int init_stream_server(struct cluster_args *args);

/*
 * Global verbose flag
 */
extern bool verbose;

#define VLOGF(A, ...) if(verbose) { fprintf(stderr, A, ##__VA_ARGS__); }

#ifndef NMPI
#include <mpi.h>
//do not use
int nb_probe(int source, int tag, MPI_Comm comm, MPI_Status *stat);
int nb_waitany(int len, MPI_Request *reqs, int *i, MPI_Status *stat);
//Cluster broadcast funcs 
// MPI's bcast fuctions don't do quite what I want
void c_bcast_send(struct reply *r);
void c_bcast_irecv(struct reply *msg, MPI_Request *r);
void c_bcast_wait_exit(void);
#endif

#endif   /* ----- #ifndef cluster_INC  ----- */

