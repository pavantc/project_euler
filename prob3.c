#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int
is_prime(uint64_t num)
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
	uint64_t num = 600851475143;
	uint64_t d, max = 0;
	double t = num;
	int sqrt_num = ceil(sqrt(t));
	int i;

	if ((sqrt_num & 0x1) == 0) {
		// Make it an odd number larger than sqrt
		// since even numbers aren't prime numbers

		sqrt_num++;
	}

	for (i = sqrt_num; i > 1; i--) {
		if (num % i == 0) {
			d = num / i;
			if (is_prime(d) && d > max) {
				max = d;
			}

			if (is_prime(i) && i > max) {
				max = i;
			}
		}
	}

	printf("%lu\n", max);
	return (0);
}
