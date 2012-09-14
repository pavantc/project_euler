#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int digits[10] = {0,};

/* Candidate check for 1 - 9 pandigital */
int
is_candidate(int num)
{
	int d, i = num;

	memset(digits, 0, 10*sizeof(int));

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
num_digits(int num)
{
	int c = 0;
	while (num) {
		num = num/10;
		c++;
	}
	return (c);
}

int
main()
{
	int i, j, nd;
	int prod, cand, max = 0;
	char numstr[32];

	/*
	 * We stop the loop at 9999 since any number after that multiplied by
	 * atleast 1 and 2 and concatenated will results in more than 9 digits.
	 */
	for (i = 1; i < 10000; i++) {
		memset(numstr, 0, 32);
		nd = 0;
		for (j = 1; j < 10; j++) {
			prod = i * j;
			nd += num_digits(prod);
			sprintf(numstr, "%s%d", numstr, prod);
			if (nd >= 9) {
				break;
			}
		}
		if (nd == 9) {
			cand = atoi(numstr);
			if (is_candidate(cand) && cand > max) {
				max = cand;
			}
		}
	}
	printf("%d\n", max);

	return (0);
}
