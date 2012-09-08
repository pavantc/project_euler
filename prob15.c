#include <stdio.h>
#include <stdint.h>

/*
 * A     B  
 *  +---+
 *  |   |
 *  +---+
 * C     D 
 *
 * In the 1X1 grid above,
 * There is 1 way to get to B from A.
 * There is 1 way to get to C from A.
 * Lets adopt a symbolic notation -
 * toX => number of ways in which one can get to X
 *
 * Representing the above in symbolic notation -
 * toB = 1
 * toC = 1
 * toD = toB + toC = 1+1 = 2
 * How we arrived at the equation for toD needs some explanation. 
 * There are only two ways through which one can reach D -> either through B or
 * through C. So,
 * Total number of ways in which one can read D =
 * no. of ways in which one can reach B + no. of ways in which one can reach C
 *
 * Lets look at a 2X2 grid:
 *
 * A    B    C
 *  +---+---+
 *  |  E|   |
 * D+---+---+F
 *  |   |   |
 *  +---+---+
 * G    H    I
 *
 * toB = toC = 1
 * toD = toG = 1
 *
 * 0    1    1
 *  +---+---+
 *  |   |   |
 * 1+---+---+ 
 *  |   |   |
 *  +---+---+
 * 1
 *
 * From the above,
 * 	toE = toB + toD = 1 + 1 = 2
 *	toF = toE + toC = 2 + 1 = 3
 *	toH = toG + toE = 1 + 2 = 3
 *	toI = toF + toH = 3 + 3 = 6
 *
 * Using the same logic, we get to the total number of ways for a 20X20 grid.
 */

int
main()
{
	uint64_t a[21][21] = {
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	int i, j;

	for (i = 1; i < 21; i++) {
		for (j = 1; j < 21; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}

	printf("%lu\n", a[20][20]);

	return (0);
}
