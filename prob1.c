#include <stdio.h>

/*
 * mathematically, it can be solved by -
 * 3 * (1 + 2 + ... + 333) + 5 * (1 + 2 + ... + 199) - 15(1 + 2 + ... + 66)
 * The subtraction is because we would have added multiples of 15 twice while
 * adding the multiples of 3 and 5
 * Sum to n terms of natural numbers is given by:
 *
 * n * (n + 1)
 * -----------
 *      2
 */
int
main()
{
	int i, sum = 0;

	for (i = 0; i < 1000; i += 5) {
		sum += i;
	}

	for (i = 0; i < 1000; i += 3) {
		sum += i;
	}

	for (i = 0; i < 1000; i += 15) {
		sum -= i;
	}

	printf("Sum : %d\n", sum);
}
