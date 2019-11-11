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
#include "cluster.h"

int _fnum = 0;
//dummy method
int get_frame(void **frame)
{
	*frame = malloc(sizeof(char) * 40);
	strcpy("Frame", *frame + 4);
	*((int *) *frame) = _fnum;
	return _fnum++;
}

int init_input(struct cluster_args *params, buf_handle_t *buf)
{
	return 0;
}

