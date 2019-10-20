/*
 * buffer.h
 * 
 * 
 */
#ifndef BUFFER_H
#define BUFFER_H
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <assert.h>

#include "gpr_allocator.h"
#include "gpr_buffer.h"

//define buffer structure

typedef struct buf_t buf_t;

typedef buf_t* buf_handle_t;


void buf_reset(buf_handle_t buf);
buf_handle_t buf_init(gpr_buffer* buffer, size_t size);
void buf_free(buf_handle_t buf);
bool buf_full(buf_handle_t buf);
bool buf_empty(buf_handle_t buf);
size_t buf_size(buf_handle_t buf);
void buf_put(buf_handle_t buf, gpr_buffer * data);
int buf_get(buf_handle_t buf, gpr_buffer * data);
#endif // BUFFER_H
