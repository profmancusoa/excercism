#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>

const int *binary_search(int value, const int *arr, size_t length);
const int *_binary_search(int value, const int *arr, int s, int e);
int compare (const void *elem1, const void *elem2);

#endif
