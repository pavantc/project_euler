#include <stdio.h>
#include <stdlib.h>

#define SQ(x) (x * x)

int
main()
{
	int a, b, c, sum;

	for (a = 997; a > 0; a--) {
		sum = 1000 - a;
		for (b = 1; b < sum; b++) {
			c = sum - b;
			if (SQ(a) == (SQ(b) + SQ(c))) {
				printf("Found - %d, %d, %d, prod = %d\n", a, b,
				    c, a*b*c);
				break;
			}
		}
	}

	return (0);
}
