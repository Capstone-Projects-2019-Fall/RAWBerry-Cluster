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

#include "buffer.h"

#define NODE_MASTER 0
#define NODE_COLLECTOR 1
#define NSLAVE_START   2
#define TAG_S_RET 1
#define TAG_S_TO  2
#define TAG_B_ALRT 3

#ifndef TEST
#define FRAME_RAW_SIZEB (3840 * 2160 * 3 + 8)
#else 
#define FRAME_RAW_SIZEB 40
#endif


struct cluster_args{
	char *source;
	long compopts;
	//TODO: add additional ops as needed 
};

struct reply{
	uint8_t  message;
	uint8_t  padding[3];
	int32_t payload;
};

#define REPLY_MSG_SUCCESS  0x01

extern int this_node_rank;
extern int num_nodes;

int init_mpi(void);
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
int get_frame(void **frame);
int master_done(void);

//Slave node funcs

int slave(struct cluster_args *params);
int init_engine(struct cluster_args *params);
int slave_done(void);

//collector node funcs

int collector(struct cluster_args *args);
int collector_done(void);
int init_stream_server(struct cluster_args *args);

#ifndef NMPI
#include <mpi.h>
int nb_probe(int source, int tag, MPI_Comm comm, MPI_Status *stat);
int nb_waitany(int len, MPI_Request *reqs, int *i, MPI_Status *stat);
#endif

#endif   /* ----- #ifndef cluster_INC  ----- */

