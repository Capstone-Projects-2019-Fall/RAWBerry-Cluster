/*
 * =============================================================================
 *
 *       Filename:  util.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/19/2019 03:51:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Gruda, tuh37025@temple.edu
 *   Organization:  
 *
 * =============================================================================
 */


#ifndef  util_INC
#define  util_INC
#include <stdio.h>
#include <stdlib.h>

#define XCALLOC(A, S, M) 							\
	A = calloc(S, M); 							\
	if(!A){       								\
		fprintf(stderr, "Cannot alloc memory of %s size %d\n", 		\
			#A, S * M); 						\
	} 



#endif   /* ----- #ifndef util_INC  ----- */
