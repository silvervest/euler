/* Project Euler - Problem #6

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

#include <stdio.h>
#include <math.h>

int main(void) {
    unsigned int squares = 0, sum = 0, i = 0;

    for (i = 1; i < 101; i++) {
        squares += (unsigned int)pow(i, 2);
        sum += i;
    }

    printf("diff = %i\n", ((unsigned int)pow(sum, 2) - squares));

    return 0;
}
