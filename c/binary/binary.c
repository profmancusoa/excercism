#include "binary.h"
#include <string.h>
#include <math.h>

#define INVALID -1

int convert(const char *input) {
    int len = (int)strlen(input);
    int dec = 0;

    if(len > 0) {
        for(int i = 0; i < len; i++) {
            if(input[i] != '0' && input[i] != '1') return INVALID;
            if(input[i] == '1') {
                dec += (int)pow(2, len-i-1);    
            }
        }   
        return dec;
    }

    return INVALID;
}