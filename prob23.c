#include <stdio.h>
#include <math.h>

int
get_sum_of_divisors(int num)
{
	double t = num;
	int sq_root = ceil(sqrt(t));
	int i, j, sum_of_divisors = 1;

	for (i = sq_root; i > 1 && i != num; i--) {
		if ((num % i) == 0) {
			j = num / i;
			if (j <= sq_root) {
				/* lest we account for these numbers twice */
				sum_of_divisors += i;
			} else {
				sum_of_divisors += (i + j);
			}
		}
	}
	return (sum_of_divisors);
}

int
main()
{
	int i, j, sa, sb;
	int sum = 0;
	int found;

	for (i = 1; i < 24; i++) {
		sum += i;
	}

	for (; i < 28123; i++) {
		found = 0;
		for (j = 1; j <= i/2; j++) {
			sa = get_sum_of_divisors(j);
			sb = get_sum_of_divisors(i-j);

			if ((sa > j) && (sb > (i-j))) {
				/*
				 * Found a number which can be expressed as a
				 * sum of two abundant numbers;
				 */
				 found = 1;
				 //printf("%d: %d + %d\n", i, j, (i-j));
				 break;
			}
		}
		if (!found) {
			sum += i;
		}
	}

	printf("%d\n", sum);
	return (0);
}
