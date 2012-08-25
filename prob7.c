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
main()
{
	int i;
	int count = 1;

	for (i = 3; ;i += 2) {
		if (is_prime(i)) {
			if (++count == 10001) {
				printf("%d\n", i);
				return (0);
			}
		}
	}
	/* NOTREACHED */
	return (0);
}
