#include <stdio.h>

/*
 * We start from the last-but-one row.
 * The first number in this row is 63. The paths reachable from 63 are:
 * ls (left-sum): 63->4
 * rs (right-sum): 63->62
 * The path with the largest sum of the two is 63->62.
 * From the perspective of the best path from 63, we can simply overwrite 63
 * with the sum (63+62) since this is what one will always take given the
 * max-path-sum criteria. Continuing in this fashion, we find the max-path-sum
 * for all the numbers in the last-but-one row, and overwrite them with their
 * max-path-sum.
 * Now, moving one row above, we do the same for all the numbers in that row.
 * In this fashion, we get to a[0][0] which would finally have the
 * max-path-sum.
 */
int
main()
{
	int a[15][15] = {
		75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0,
		99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0,
		41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0,
		41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0,
		53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0,
		70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0,
		91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0,
		63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0,
		4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23
	};
	int i, j, ls, rs;

	for (i = 13; i >= 0; i--) {
		for (j = 0; j < i+1; j++) {
			ls = a[i][j] + a[i+1][j];
			rs = a[i][j] + a[i+1][j+1];
			a[i][j] = (ls > rs) ? ls : rs;
		}
	}
	printf("%d\n", a[0][0]);

	return (0);
}
