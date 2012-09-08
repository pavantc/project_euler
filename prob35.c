#include <stdio.h>
#include <math.h>

int
is_prime(int num)
{
	double t = num;
	int sq_root = ceil(sqrt(t));
	int i;

	for (i = sq_root; i > 1; i--) {
		if (num % i == 0) {
			return (0);
		}
	}
	return (1);
}

int
is_rot_prime(int i, int d)
{
	int rn = i;

	if (rn%5 == 0) {
		return (0);
	}
	do {
		if (!is_prime(rn)) {
			return (0);
			break;
		}
		rn = ((rn % d) * 10) + rn/d;
	} while (rn != i);

	return (1);
}

int
main()
{
	int i, c = 13;

	for (i = 101; i < 1000; i+=2) {
		if (is_rot_prime(i, 100)) {
			c++;
		}
	}
	for (i = 1001; i < 10000; i+=2) {
		if (is_rot_prime(i, 1000)) {
			c++;
		}
	}
	for (i = 10001; i < 100000; i+=2) {
		if (is_rot_prime(i, 10000)) {
			c++;
		}
	}
	for (i = 100001; i < 1000000; i+=2) {
		if (is_rot_prime(i, 100000)) {
			c++;
		}
	}
	printf("%d\n", c);
	return (0);
}
