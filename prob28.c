#include <stdio.h>

int
main()
{
	int sum, i, skip;
	int s = 1001;

	for (i = 1, sum = 1, skip = 2; i < s * s; i += 4*skip, skip += 2) {
		/*
		 * 4 corners of the square are -> (i+skip), (i+2*skip),
		 * (i+3*skip), (i+4*skip). Adding them all gives the sum of
		 * terms on diagonals at each spiral.
		 */
		sum += 4*i + 10*skip;
	}
	printf("%d\n", sum);
	return (0);
}

