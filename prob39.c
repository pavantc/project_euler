#include <stdio.h>
#include <stdlib.h>

#define SQ(x) (x * x)

int
main()
{
	int a, b, c, n, sum, max = 0, max_n, count;

	for (n = 1000; n > 5; n--) {
		count = 0;
		for (a = n-3; a > 0; a--) {
			sum = n - a;
			for (b = 1; b < sum; b++) {
				c = sum - b;
				if (SQ(a) == (SQ(b) + SQ(c))) {
					count++;
				}
			}
		}
		if (count > max) {
			max = count;
			max_n = n;
		}
	}

	printf("%d\n", max_n);
	return (0);
}
