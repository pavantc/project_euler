#include <stdio.h>
#include <stdint.h>
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
	int count = 1, i;
	uint64_t sum = 2; // Initialized to the first prime

	for (i = 3; i < 2000000; i += 2) {
		if (is_prime(i)) {
			sum += i;
		}
	}

	printf("%lu\n", sum);
	return (0);
}
