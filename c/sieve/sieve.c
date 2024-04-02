#include "sieve.h"
#include <math.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    size_t count = 0;
    size_t size = limit + 1;
    int sieve[size];

    if(limit > 1) { 
        //init the sieve
        for(size_t i = 0; i < size; i++)
            sieve[i] = i;
        
        //scan the sieve from 2 to limit
        for(size_t i = 2; i <= (size_t)limit; i++) {
            //if scanned number is != 0 then is prime
            if(sieve[i] != 0)
                primes[count++] = sieve[i];

            //limit to max_primes result
            if(count == max_primes) break;

            //mark (put it to 0) all the multiple of scanned number
            size_t m = 2, j = 0;
            while((j = i * m) <= limit) {
                sieve[j] = 0;
                m++;
            }
        }
    }
    
    return count;
}