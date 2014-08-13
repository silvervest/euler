#include <stdio.h>

int main(void) {
	/*
	i + prev = val;
	0 + 1 = 1;
	1 + 1 = 2;
	1 + 2 = 3;
	2 + 3 = 5;
	3 + 5 = 8;
	5 + 8 = 13;
	*/

	int i = 1;
	int prev = 0;
	int sum = 0;

	while (prev + i < 4000000) {
		int val = prev + i;
		prev = i;
		i = val;

		if (val % 2 == 0) {
			sum += val;
		}

		printf("%i, ", val);
	}

	printf("\nsum = %i\n", sum);

	return;
}