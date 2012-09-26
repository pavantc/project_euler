#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

int
main()
{
	int i, j, k, fail;

	for (i = 9; ; i += 2) {
		if (is_prime(i)) {
			continue;
		}
		fail = 0;
		for (j = 1; ; j++) {
			k = i;
			if (2*j*j >= k) {
				break;
			}
			k -= 2*j*j;
			if (is_prime(k)) {
				fail = 1;
				break;
			}
		}
		if (!fail) {
			printf("%d\n", i);
			break;
		}
	}

	return (0);
}
