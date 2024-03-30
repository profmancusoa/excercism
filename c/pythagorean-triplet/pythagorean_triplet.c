#include "pythagorean_triplet.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void free_triplets(triplets_t *triplet) {
    free(triplet);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void order_abc(int *a, int *b, int *c) {
    if(*a > *c) swap(a, c);
    if(*a > *b) swap(a, b);
    if(*b > *c) swap(b, c);
}

bool is_triple_present(triplets_t *db, int a, int b, int c) {
    for(int i = 0; i < db->count; i++)
        if(db->triplets[i].a == a &&
           db->triplets[i].b == b &&
           db->triplets[i].c == c) return true;

    return false;
}

void add_triplet(triplets_t *db, int a, int b, int c) {
    db->triplets[db->count] = (triplet_t){ a, b, c };
    db->count += 1;
}

triplets_t *triplets_with_sum(int sum) {
    triplets_t *db = (triplets_t *)malloc(sizeof(triplets_t));
    memset(db, 0, sizeof(triplets_t));
    
    //I use the Euclid's formula 
    //https://en.wikipedia.org/wiki/Pythagorean_triple
    
    int m = 2;
    while(m < sum) {
        int n = 1;
        while(n < m) {
            int a = m*m - n*n;
            int b = 2*m*n;
            int c = m*m + n*n;
            int add = a + b + c;

            //for some reason the solution is expecting a ordered triplet
            order_abc(&a, &b, &c);

            //if it is a primitive triplet and not already added I add it
            if(add == sum && !is_triple_present(db, a, b, c)) 
                add_triplet(db, a, b, c);
    
            //if it is not a primitive triplet I calculate the derivate triplet
            //and if not added I add it 
            if(add < sum && sum % add == 0) {
                int factor = sum / add;
                a *= factor;
                b *= factor;
                c *= factor;

                if(!is_triple_present(db, a, b, c)) 
                    add_triplet(db, a, b, c);          
            }
            n++;
        }
        m++;
    }
    return db;
}