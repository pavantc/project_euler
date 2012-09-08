#include <stdio.h>
#include <math.h>
#include <stdint.h>

/* Faster algorithm than prob23.c, but still lousy */

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

int ab_nums[32*1024] = {0, };

int
found_in_ab_nums(int t, int c)
{
	int s = 0, e = c, i;

	while (s <= e) {
		i = (s + e)/2;
		if (t == ab_nums[i]) {
			return (1);
		}
		
		if (t < ab_nums[i]) {
			e = i - 1;
		} else {
			s = i + 1;
		}
	}
	return (0);
}


int
main()
{
	int i, j, k;
	int found, sa, sb, sum = 0;

	for (i = 12, j = 0; i < 28123; i++) {
		sum = get_sum_of_divisors(i);
		if (sum > i) {
			ab_nums[j++] = i;
		}
	}

	sum = 0;
	for (i = 1; i < 24; i++) {
		sum += i;
	}

	for (; i < 28123; i++) {
		found = 0;
		for (k = 1; k <= i/2; k++) {
			sa = found_in_ab_nums(k, j);
			sb = found_in_ab_nums((i-k), j);

			if (sa && sb) {
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
