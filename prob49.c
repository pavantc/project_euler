#include <stdio.h>
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

void
to_digit(int *a, int i)
{
	int k = 0;
	while (i) {
		a[k++] = i % 10;
		i = i/10;
	}
}

int
found(int *a, int k)
{
	int i = 0;
	int found = 0;

	for (i = 0; i < 4; i++) {
		if (k == a[i]) {
			found = 1;
			a[i] = -1;
			break;
		}
	}
	return (found);
}

int
is_perm(int i, int j, int k)
{
	int a[4] = {0}, b[4] = {0}, c[4] = {0};
	int copy[4] = {0};
	int *p, cnt, n;

	to_digit(a, i);
	to_digit(b, j);
	to_digit(c, k);

	for (n = 0; n < 4; n++) {
		copy[n] = a[n];
	}
	for (p = &b[0], cnt = 0; cnt < 4; cnt++, p++) {
		if (!found(copy, *p)) {
			return (0);
		}
	}

	for (n = 0; n < 4; n++) {
		copy[n] = a[n];
	}
	for (p = &c[0], cnt = 0; cnt < 4; cnt++, p++) {
		if (!found(copy, *p)) {
			return (0);
		}
	}
	return (1);
}

int
main()
{
	int i, j;
	for (i = 1001; i < 10000; i+=2) {
		if (!is_prime(i)) {
			continue;
		}
		for (j = 1; j < 10000 - i; j++) {
			if (i + j > 9999) {
				break;
			}
			if (!is_prime(i+j)) {
				continue;
			}
			if (i + 2*j > 9999) {
				break;
			}
			if (is_prime(i+2*j)) {
				if (is_perm(i, i+j, i+2*j)) {
					printf("%d\t%d\t%d\n", i, i+j, i+2*j);
				}
			}
		}
	}
	return (0);
}
