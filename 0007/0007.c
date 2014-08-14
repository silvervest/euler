/* Project Euler - Problem #7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

#include <stdio.h>
#include <limits.h>

int is_prime(int num) {
    int i;
    for (i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    int i, primes = 1;

    /* brute forcing it again */
    for (i = 3; i < INT_MAX; i++) {
        if (i % 2 == 0) continue;
        if (is_prime(i)) {
            primes++;
        }

        if (primes == 10001) {
            printf("10001st prime is %i\n", i);
            break;
        }
    }

    return 0;
}
