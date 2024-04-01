#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

typedef int buffer_value_t;
typedef struct _circular_buffer_t {
    int capacity; //max slot in the buffer
    int size;     //current number of slot in the buffer
    int oldest;   //index of oldest written slot
    int newest;   //index of latest written slot
    buffer_value_t *slots;
} circular_buffer_t;


circular_buffer_t *new_circular_buffer(size_t capacity);
void delete_buffer(circular_buffer_t *buffer);
void clear_buffer(circular_buffer_t *buffer);
int16_t read(circular_buffer_t *buffer, buffer_value_t *val);
int16_t write(circular_buffer_t *buffer, buffer_value_t val);
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t val);

#endif
