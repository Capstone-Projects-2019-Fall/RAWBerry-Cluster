/*
 * =============================================================================
 *
 *       Filename:  stubs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/18/2019 07:29:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Gruda (mg), matthewgruda@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "cluster.h"
#include "sopool.h"

int main(int argc, char **argv)
{
	struct sopool s;
	sopool_init(&s, 50, 3, -2);
	int i = 0;
	for(; i < 500; i++){
		void *v = sopool_get_new(&s);
		if(i % 2 == 0){
			sopool_return(&s, v);
		}
	}
	init_mpi();
	cluster(NULL);
	exit_mpi();
	return 0;
}

int init_stream_server(struct cluster_args *params)
{
	return 0;
}

void _s_compress(void *in, void **out, int *sz)
{
	sleep(1);
	*out = malloc(40);
	memcpy(*out, in, 40);
	*sz = 40;
}

int _fnum = 0;
//dummy method
int get_frame(void **frame)
{
	char *nf = malloc(sizeof(char) * 40);
	strcpy(nf + 4, "Frame");
	*((int *) nf) = _fnum;
	printf("Got frame %d\n", _fnum);
	*frame = nf;
	return _fnum++;
}

int init_engine(struct cluster_args *params)
{
	return  0;
}

int init_input(struct cluster_args *params, buf_handle_t *buf)
{
	return 0;
}

