#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value) {
    size_t len = strlen(value); 
    char *str = (char *)malloc(len + 1);
    memset(str, 0, len + 1);

    for(size_t i = 0; i < len; i++)
        str[i] = value[len - 1 - i];

    return str;
}

// char *reverse(const char *value) {
//     size_t len = strlen(value); 
//     char *str = (char *)malloc(len + 1);
 
//     for(size_t i = 0; i < len; i++)
//         str[i] = value[len - 1 - i];
//     str[len] = '\0';
    
//     return str;
// }
