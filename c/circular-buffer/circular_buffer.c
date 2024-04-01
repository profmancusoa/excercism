#include "circular_buffer.h"

#define CALC_BOUND(b) ((b + 1) % buffer->capacity)

circular_buffer_t *new_circular_buffer(size_t capacity) {
    circular_buffer_t *buffer = (circular_buffer_t *)malloc(sizeof(circular_buffer_t));
    *buffer = (circular_buffer_t) {
        capacity,
        0,
        -1,
        -1,
        (buffer_value_t *)malloc(sizeof(buffer_value_t) * capacity)
    };
    
    return buffer;
}

void delete_buffer(circular_buffer_t *buffer) {
    if (buffer != NULL && buffer->slots != NULL) { 
        free(buffer->slots);
        free(buffer);
    }
}

void clear_buffer(circular_buffer_t *buffer) {
    if (buffer != NULL && buffer->slots != NULL) {
        buffer->size = 0;
        buffer->newest = 0;
        buffer->oldest = 0;
    }
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *val) {
    if(buffer != NULL && buffer->slots != NULL) {
        if(buffer->size == 0) {
            errno = ENODATA;
            return EXIT_FAILURE;
        }

        //
        *val = buffer->slots[buffer->oldest];
        buffer->oldest = (buffer->oldest + 1) % buffer->capacity;
        buffer->size--;

        if(buffer->size == 0) {
            buffer->oldest = -1;
            buffer->newest = -1;
        }
        
        return EXIT_SUCCESS;
    }
       
    errno = ENOBUFS;
    return EXIT_FAILURE;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t val) {
    if(buffer != NULL && buffer->slots != NULL) {
        if(buffer->size < buffer->capacity) {
            buffer->newest = CALC_BOUND(buffer->newest);
            buffer->slots[buffer->newest] = val;
            if(buffer->oldest == -1) buffer->oldest = 0;
            buffer->size++;
            return EXIT_SUCCESS;
        }
    }
       
    errno = ENOBUFS;
    return EXIT_FAILURE;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t val) {
    if(buffer != NULL && buffer->slots != NULL) {
        if(buffer->size < buffer->capacity)
            return write(buffer, val);
        if(buffer->size == buffer->capacity) {
            buffer->slots[buffer->oldest] = val;
            buffer->oldest = CALC_BOUND(buffer->oldest);
            buffer->newest = CALC_BOUND(buffer->newest);
            return EXIT_SUCCESS;
        }
    }
       
    errno = ENOBUFS;
    return EXIT_FAILURE;
}