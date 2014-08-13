/* Project Euler - Problem #3

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <stdio.h>

int main(void) {
	unsigned long num = 600851475143;
	unsigned long factor = 0;

	/* immediately obvious there's no factor of two, so skip this 
	while (num % 2 == 0) {
		factor = 2;
		num /= 2;
	}
	*/

	/* find odd factors */
	unsigned long divisor = 3;
	while (num != 1) {
		while (num % divisor == 0) {
			factor = divisor;
			num /= divisor;
		}
		divisor += 2;
	}

	printf("largest factor %lu\n", factor);

	return;
}