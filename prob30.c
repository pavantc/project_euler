#include <stdio.h>

int
main()
{
	int i, sum = 0, s, n, k;

	/*
	 * Why are we looping only till about 400000?
	 * Rationale:
	 * The maximum amount that can be contributed by each digit to the sum
	 * of digits is 9^5. Beyond 6 digits, the number starts getting way too
	 * large and the sum of the 5th power of the digits of the number
	 * cannot catch up with the number any more.
	 */
	for (i = 2; i < 400000; i++) {
		k = i;
		s = 0;
		while(k) {
			n = k%10;
			k = k/10;
			s += n * n * n * n * n;
		}
		if (s == i) {
			sum += i;
		}
	}
	printf("%d\n", sum);
	return (0);
}
