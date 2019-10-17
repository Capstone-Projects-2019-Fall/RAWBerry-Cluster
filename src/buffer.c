/*
 * buffer.c
 * 
 */

#include "buffer.h"


//Our Glorious Buffer
struct buf_t {
    uint8_t * buffer;
    size_t head;
    size_t tail;
    size_t max; 
    bool full;
};




//First we need a way to initialize this thing
buf_handle_t buf_init(uint8_t* buffer, size_t size)
{
    assert(buffer && size);

    buf_handle_t buf = malloc(sizeof(buf_t));
    assert(buf);

    buf->buffer = buffer;
    buf->max = size;
    buf_reset(buf);

    assert(buf_empty(buf));

    return buf;
}

//Simple way to get the thing empty

void buf_reset(buf_handle_t buf)
{
    assert(buf);

    buf->head = 0;
    buf->tail = 0;
    buf->full = false;
}

//So we can get rid of these, don't want annoying memory leaks
void buf_free(buf_handle_t buf)
{
    assert(buf);
    free(buf);
}
//See if there's space for more stuff
bool buf_full(buf_handle_t buf)
{
    assert(buf);

    return buf->full;
}
//May need to catch up soon...
bool buf_empty(buf_handle_t buf)
{
    assert(buf);

    return (!buf->full && (buf->head == buf->tail));
}
//So uh, how big am I? Too big, or just right...
size_t buf_capacity(buf_handle_t buf)
{
    assert(buf);

    return buf->max;
}


size_t buf_size(buf_handle_t buf)
{
    assert(buf);

    size_t size = buf->max;
	//If full this is just max
    if(!buf->full)
    {
        if(buf->head >= buf->tail)
        {
            //If head is a head of the tail, just subtract
            size = (buf->head - buf->tail);
        }
        else
        {
			//If tail is ahead, add offset
            size = (buf->max + buf->head - buf->tail);
        }
    }

    return size;
}


//Add a few helper functions
static void adv_pointer(buf_handle_t buf)
{
    assert(buf);

    if(buf->full)
       {
        buf->tail = (buf->tail + 1) % buf->max;
    }

    buf->head = (buf->head + 1) % buf->max;
    buf->full = (buf->head == buf->tail);
}

static void ret_pointer(buf_handle_t buf)
{
    assert(buf);

    buf->full = false;
    buf->tail = (buf->tail + 1) % buf->max;
}

//Lets do something fun, how about stick something in this thing
void buf_put(buf_handle_t buf, uint8_t data)
{
    assert(buf && buf->buffer);

    buf->buffer[buf->head] = data;

    adv_pointer(buf);
}

//Wouldn't be very useful if we can't get our stuff back...
int buf_get(buf_handle_t buf, uint8_t * data)
{
    assert(buf && data && buf->buffer);

    int r = -1;

    if(!buf_empty(buf))
    {
        *data = buf->buffer[buf->tail];
        ret_pointer(buf);

        r = 0;
    }

    return r;
}
