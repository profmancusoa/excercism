#include "hamming.h"
#include <stdio.h>
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    int distance = 0;
    
    if(lhs == NULL || 
       rhs == NULL || 
       strlen(lhs) != strlen(rhs)
    ) return -1;
    
    for(size_t i = 0; i < strlen(lhs); i++)
        if(*(lhs + i) != *(rhs + i)) distance++;

    return distance;
}