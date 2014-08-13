/* Project Euler - Problem #4

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

#include <stdio.h>
#include <string.h>

/* function to reverse a string using pointer magic 
if we were reversing the string "palindrome", this is what it does:
put the letter 'p' into a temp hold
replace the first letter 'p' with the letter 'e' from the end
replace the letter 'e' from the end with the letter 'p' from the temp store
move inwards one space
put the letter 'a' into a temp hold
replace the second letter 'a' with the penultimate letter 'm'
replace the penultimate letter 'm' with the letter 'a' from the temp hold
rinse, repeat...
*/
void reverse(char *str) {
	char *start = str;
	char *end = start + strlen(str) - 1; /* stupid off-by-one... don't touch the null at the end of the string */
	char tmp;

	while (end > start) {
		/* store the "start" in a temp */
		tmp = *start;
		/* swap the "start" and the "end" */
		*start = *end;
		/* put the temp character at the "end" */
		*end = tmp;

		/* move forward and backwards */
		++start;
		--end;
	}
}

int main(void) {
	int i, j;
	int biggest = 0;

	/* gonna brute force this one, starting at 999*999 and working down */
	for (i = 999; i > 99; i--) {
		for (j = 999; j > 99; j--) {
			char product[6]; /* 6 because 999 * 999 = 998001 */
			char rev[6];

			/* calculate the product and store as strings */
			sprintf(product, "%d", j * i);
			sprintf(rev, "%d", j * i);

			/* reverse one of them */
			reverse(rev);

			/* compare */
			if (strcmp(product, rev) == 0) {
				int val = atoi(product);
				if (val > biggest) {
					biggest = val;
				}
			}
		}
	}

	printf("largest palindrome %i\n", biggest);
	return;
}