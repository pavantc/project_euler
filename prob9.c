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
			if (a + b + c != 1000) {
				fprintf(stderr, "Error\n");
				exit(1);
			}
			if ((SQ(a) == (SQ(b) + SQ(c))) ||
			    (SQ(a) == (SQ(b) + SQ(c))) ||
			    (SQ(a) == (SQ(b) + SQ(c)))) {
				printf("Found - %d, %d, %d\n", a, b, c);
			}
		}
	}

	return (0);
}
