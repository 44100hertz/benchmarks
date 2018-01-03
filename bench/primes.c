#include <stdio.h>
#include <stdbool.h>

#include "../lib/time.h"

static bool is_prime(long n);
static long num_primes(int n);

int main()
{
        for (int i=0; i<18; ++i) {
                double start = time();
                long prime = num_primes(1<<i);
                printf("Found %6ld primes, took %4lf sec\n",
                        prime, time() - start);
        }
}

bool is_prime(long n)
{
        for (long i=2; i<=n/2; ++i) {
                if (n%i == 0) return false;
        }
        return true;
}

long num_primes(int n)
{
        int total = 0;
        for (long i=0; i<n; ++i) {
                if (is_prime(i)) {
                        ++total;
                }
        }
        return total;
}

