#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

#include <stdbool.h>

#define MAX_TRIPLETS 10

typedef struct _triplet_t {
    int a, b, c;
} triplet_t;

typedef struct _triplets_t {
    int count;
    triplet_t triplets[MAX_TRIPLETS];
} triplets_t;

triplets_t *triplets_with_sum(int sum);
void free_triplets(triplets_t *triplet);
void swap(int *a, int *b);
void order_abc(int *a, int *b, int *c);
bool is_triple_present(triplets_t *db, int a, int b, int c);
void add_triplet(triplets_t *db, int a, int b, int c);

#endif
