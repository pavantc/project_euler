#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int digits[10] = {0,};

int
is_prime(int num)
{
	double t = num;
	int sq_root = ceil(sqrt(t));
	int i;

	if (num == 1) {
		return (0);
	}

	if (num == 2) {
		return (1);
	}

	for (i = sq_root; i > 1; i--) {
		if (num % i == 0) {
			return (0);
		}
	}
	return (1);
}

/* Candidate check for 1 - 9 pandigital */
int
is_candidate(int num, int limit)
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

	for (i = 1; i <= limit; i++) {
		if (digits[i] == 0) {
			return (0);
		}
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
	int i, nd;

	/* Brute force. There is a better implementation in prob41a.c */
	for (i = 987654321; i > 1; i--) {
		nd = num_digits(i);
		if (is_candidate(i, nd) && is_prime(i)) {
			printf("%d\n", i);
			break;
		}
	}

	return (0);
}
