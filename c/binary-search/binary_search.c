#include "binary_search.h"
#include <stdio.h>
#include <stdlib.h>

int compare (const void *elem1, const void *elem2) {
    return *(int *)elem1 - *(int *)elem2;
}

const int *binary_search(int value, const int *arr, size_t length) {
        if (length == 1) return arr;
        qsort((void *)arr, length, sizeof(int), compare);
        return _binary_search(value, arr, 0, length - 1);
}

const int *_binary_search(int value, const int *arr, int s, int e) {
    int pivot = s + ((e - s + 1) / 2);

    if(e < s) return NULL;
    if(arr[pivot] == value) return &arr[pivot];
    if(arr[pivot] > value) return _binary_search(value, arr, s, pivot - 1);
    if(arr[pivot] < value) return _binary_search(value, arr, pivot + 1, e);

    return NULL;
}