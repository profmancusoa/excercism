#include "isogram.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

bool is_isogram(const char phrase[]) {
    if(phrase == NULL) return false;
    
    int len = strlen(phrase);
    if(len > 0) {
        char phrasel[len + 1];
        //copy and convert to lowercase phrase
        for(int i = 0; i < len; i++)
            phrasel[i] = tolower(phrase[i]);
        phrasel[len] = '\0';

        for(int i = 0; i < len; i++) {
            char c = phrasel[i];
            if (c == '-' || c == ' ') continue;
            if(strcmp(strchr(phrasel, c),strrchr(phrasel, c)) != 0) return false;
        }
    }
    return true;
}