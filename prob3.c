#include <stdio.h>
#include <stdlib.h>
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
	uint64_t num = 600851475143;
	double t = num;
	int sqrt_num = ceil(sqrt(t));
	int i;

	if ((sqrt_num & 0x1) == 0) {
		// Make it an odd number larger than sqrt
		// since even numbers aren't prime numbers

		sqrt_num++;
	}

	for (i = sqrt_num; i > 0; i-=2) {
		if ((i % 5) == 0) {
			continue;
		}
		if (is_prime(i)) {
			if ((num % i) == 0) {
				/* Found */
				printf("%d\n", i);
				break;
			}
		}
	}
	return (0);
}
