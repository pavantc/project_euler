#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int digits[10] = {0,};

int
is_candidate(int num)
{
	int d, i = num;
	while (i) {
		d = i % 10;
		if (d == 0) {
			return (0);
		}
		i = i / 10;
		if (digits[d] != 0) {
			return (0);
		}
		digits[d] = d;
	}
	return (1);
}

int
main()
{
	int i, j;
	int prod, sum = 0;

	/*
	 * It can be verified that only a combination of (1,4) and (2,3) (where
	 * the pair represents the number of digits of the multiplier and
	 * multiplicand) will result in a product that can be a candidate for
	 * 1-9 pandigital. For the rest of the cases, the number of digits in
	 * the equation - multipler * multiplicand = product, will not be equal
	 * to 9. Hence the two loops below, addressing the two possible
	 * combinations.
	 */
	for (i = 2; i < 10; i++) {
		for (j = 1000; j < 5000; j++) {
			memset(digits, 0, 10 * sizeof(int));
			digits[i] = i;
			if (!is_candidate(j)) {
				continue;
			}
			prod = i * j;
			if (prod >= 10000) {
				continue;
			}
			if (!is_candidate(prod)) {
				continue;
			}
			sum += prod;
			printf("%d * %d = %d\n", i, j, prod);
		}
	}

	for (i = 11; i < 100; i++) {
		memset(digits, 0, 10 * sizeof(int));
		if (!is_candidate(i)) {
			continue;
		}
		for (j = 100; j < 999; j++) {
			memset(digits, 0, 10 * sizeof(int));
			if (!is_candidate(i)) {
				/* Should never come here */
				printf("Unexpected - %d\n", i);
				exit(1);
			}
			if (!is_candidate(j)) {
				continue;
			}
			prod = i * j;
			if (prod >= 10000) {
				continue;
			}
			if (!is_candidate(prod)) {
				continue;
			}
			printf("%d * %d = %d\n", i, j, prod);
			sum += prod;
		}
	}
	return (0);
}
