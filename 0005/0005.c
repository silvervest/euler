/* Project Euler - Problem #5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/* terrible brute force method, really slow
start at 1 and increment, dividing by 1 through 20 until you find it
*/
int brute() {
    int i = 1, j;

    while (i < INT_MAX) {
        for (j = 1; j < 20 && i % j == 0; j++);
        if (j == 20) {
            return i;
        }

        i++;
    }

    return 0;
}

int main(void) {
    clock_t begin, end;
    double time_spent;
    int num = 0;

    begin = clock();
    num = brute();
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("brute method, %i - time spent, %fs\n", num, time_spent);

    return 0;
}
