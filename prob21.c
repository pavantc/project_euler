#include <stdio.h>
#include <math.h>

int
get_sum_of_divisors(int num)
{
	double t = num;
	int sq_root = ceil(sqrt(t));
	int i, j, sum_of_divisors = 1;

	for (i = sq_root; i > 1; i--) {
		if ((num % i) == 0) {
			j = num / i;
			if (j <= sq_root) {
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
	int a, da, db;
	int sum = 0;

	for (a = 1; a < 10000; a++) {
		da = get_sum_of_divisors(a);
		db = get_sum_of_divisors(da);
		if ((da != a) && (db == a)) { 
			sum += (a + da);
			printf("%d\t%d\t%d\n", a, da, db);
		}
	}

	/*
	 * Final sum = sum/2 since we would have accounted for these numbers
	 * twice.
	 */
	printf("%d\n", sum/2);
	return (0);
}
