#include <stdio.h>
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
is_trunc_prime(int i, int p)
{
	int rn = i;

	/* Right truncation */
	while(rn) {
		if (!is_prime(rn)) {
			return (0);
		}
		rn = rn/10;
	}

	rn = i;

	/* Left truncation */
	while(rn) {
		if (!is_prime(rn)) {
			return (0);
		}
		rn = rn % p;
		p = p / 10;
	}

	return (1);
}

int
main()
{
	int i, c = 0, p = 10, q = 100, sum = 0;

	for (i = 11; ; i+=2) {
		if (i > q) {
			q = q * 10;
			p = p * 10;
		}
		if (is_trunc_prime(i, p)) {
			c++;
			sum += i;
		}
		if (c == 11) {
			break;
		}
	}

	printf("%d\n", sum);
	return (0);
}
