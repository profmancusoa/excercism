#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

char *strdup(const char *str) {
    char *dup = malloc(strlen(str) + 1);
    if(dup)
        strcpy(dup, str);
    
    return dup;
}

bool is_isogram(const char phrase[]) {
    if(phrase == NULL) return false;
    
    int len = strlen(phrase);
    if(len > 0) {
        //copy and convert to lowercase phrase
        char *phrasel = strdup(phrase);
        for(int i = 0; i < len; i++)
            phrasel[i] = tolower(phrase[i]);

        for(int i = 0; i < len; i++) {
            char c = phrasel[i];
            if (c == '-' || c == ' ') continue;
            if(strcmp(strchr(phrasel, c),strrchr(phrasel, c)) != 0) return false;
        }
    }
    return true;
}

int main() {
    printf("isograms is a isogram: %d\n", is_isogram("Alphabet"));
    printf("isograms is a isogram: %d\n", is_isogram("thumbscrew-japingly"));

    return 0;
}