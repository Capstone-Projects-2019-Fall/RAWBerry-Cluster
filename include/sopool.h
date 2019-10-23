/*
 * =============================================================================
 *
 *       Filename:  sopool.h
 *
 *    Description:  Simple object pool
 *
 *        Version:  1.0
 *        Created:  10/19/2019 04:32:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Gruda (mg), matthewgruda@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */
#ifndef  sopool_INC
#define  sopool_INC

#include <stdlib.h>

struct sopool{
	void **data;
	uint16_t *refs;
	ssize_t osz;
	int sz;
	int fo;
	int gh;
};

#define SOPOOL_HINT_DOUBLE -1
#define SOPOOL_HINT_GROW_1 -2

static int sopool_init(struct sopool *s, ssize_t osize, int initial_hint, int growth_hint)
{
	int i = 0;
	s->sz = initial_hint;
	s->data = malloc(sizeof(void *) * s->sz);
	s->refs = calloc(sizeof(uint16_t), s->sz);
	while(i < s->sz){
		*(s->data + i) = malloc(osize);
		i++;
	}
	i = 0;
	s->osz = osize;
	s->gh = growth_hint;
	s->fo = 0;
	while((i < s->sz) && (*(s->data + i) = malloc(osize))) i++;
	if(i == s->sz) return 0;
	return 1;
}

static void *sopool_get_new(struct sopool *s)
{
	if(s->fo == -1){
		int sz2 = s->sz;
		if(s->gh == SOPOOL_HINT_DOUBLE){
			sz2 *= 2;
		}else if(s->gh == SOPOOL_HINT_GROW_1){
			sz2++;
		}else{
			sz2 = sz2 * 3 / 2;
		}
		s->fo = s->sz;
		s->data = realloc(s->data, sz2 * sizeof(void *));
		s->refs = realloc(s->refs, sz2 * sizeof(uint16_t));
		while(s->sz < sz2){
			*(s->data + s->sz) = malloc(s->osz);
			*(s->refs + s->sz) = 0;
			s->sz++;
		}
	}
	void *r = s->data[s->fo];
	(*(s->refs + s->fo)) = 1;
	int itr = 0;
	s->fo = (s->fo + 1) % s->sz;
	while(*(s->refs + s->fo) && itr < s->sz){
		itr++;
		s->fo = (s->fo + 1) % s->sz;
	}
	if(*(s->refs + s->fo)) s->fo = -1;
	return r;
}

static void sopool_return(struct sopool *s, void *p)
{
	int i = 0;
	while((i < s->sz) && (s->data[i] != p)) i++;
	(*(s->refs + i)) = 0;
	if(s->fo == -1){
		s->fo = i;
	}
}

#endif   /* ----- #ifndef sopool_INC  ----- */

