#include <stdio.h>

int fact_arr[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int
main()
{
	int i, s, d, fail, num, sum = 0;

	/*
	 * Rationale for choosing 2540160 as the upper bound for search:
	 * The largest seven digit number is 9999999. But the sum of factorials
	 * of its digits = 7 * 9! = 2540160. The sum is way lower than the
	 * number. With an increase in the number of digits, the number only
	 * becomes larger and larger in comparison with the sum of the
	 * factorials of the digits of the number.
	 */
	for (i = 11; i < 2540160; i++) {
		num = i;
		s = 0;
		fail = 0;
		while (num) {
			d = num%10;
			num = num/10;
			s += fact_arr[d];
			if (s > i) {
				fail = 1;
				break;
			}
		}
		if (!fail && (s == i)) {
			sum += i;
		}
	}

	printf("sum : %d\n", sum);
	return (0);
}
