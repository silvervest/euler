#include <stdio.h>

int main(void) {
    int i;
    int sum = 0;

    for (i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            printf("Found %i\n", i);
            sum += i;
        }
    }

    printf("Sum = %i\n", sum);

    return;
}
