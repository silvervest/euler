/* Project Euler - Problem #4

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

#include <stdio.h>
#include <string.h>
#include <time.h>

/* for storing the biggest palindrome found */
int biggest;

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
void reverse_str(char *str) {
	char *start = str;
	/* stupid off-by-one... don't touch the null at the end of the string */
	char *end = start + strlen(str) - 1;
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

/* function to reverse an integer mathematically
this goes through an integer starting with the right most digit and builds up
the reverse number by finding each level of 10 and decreasing the original
number by the same level
*/
int reverse_num(int num) {
	int rev = 0;

	while (num > 0) {
		rev = (rev * 10) + (num % 10);
		num /= 10;
	}

	return rev;
}

void find_via_numeric_method(int num) {
	int rev;
	rev = reverse_num(num);

	if (num == rev && num > biggest) {
		biggest = num;
	}
}

void find_via_string_method(int num) {
	char product[6]; /* 6 because 999 * 999 = 998001 */
	char rev[6];

	/* calculate the product and store as strings */
	sprintf(product, "%i", num);
	sprintf(rev, "%i", num);

	/* reverse one of them */
	reverse_str(rev);

	/* compare */
	if (strcmp(product, rev) == 0) {
		int val = atoi(product);
		if (val > biggest) {
			biggest = val;
		}
	}
}

void main(void) {
	int i, j;
	clock_t begin, end;
	double time_spent;

	begin = clock();
	/* gonna brute force this one, starting at 999*999 and working down
	   but make sure we stop when j intersects i, so we don't check dupes
	*/
	biggest = 0;
	for (i = 999; i > 99; i--) {
		for (j = 999; j >= i; j--) {
			find_via_numeric_method(i * j);
		}
	}
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("numeric method, %i - time spent, %fs\n", biggest, time_spent);

	/* string method is *quite* a lot slower, but it was the first 
	   method i used to solve this, so i'll leave it here anyway
	*/
	begin = clock();
	biggest = 0;
	for (i = 999; i > 99; i--) {
		for (j = 999; j > 99; j--) {
			find_via_string_method(i * j);
		}
	}
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("string method, %i - time spent, %fs\n", biggest, time_spent);
}
