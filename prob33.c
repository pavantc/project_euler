#include <stdio.h>

#define to_digit(a) (a - '0')

int
check_candidate(int a, int b)
{
	char x[3], y[3];
	float p, q, r, s;

	sprintf(x, "%d", a);
	sprintf(y, "%d", b);
	r = b;
	s = a;

	if (x[0] == y[0] && x[1] < y[1]) {
		p = to_digit(y[1]);
		q = to_digit(x[1]);
		if (p/q == r/s) {
			/* Found */
			return (1);
		}
	}

	if (x[0] == y[1] && x[1] < y[0]) {
		p = to_digit(y[0]);
		q = to_digit(x[1]);
		if (p/q == r/s) {
			/* Found */
			return (1);
		}
	}

	if (x[1] == y[0] && x[0] < y[1]) {
		p = to_digit(y[1]);
		q = to_digit(x[0]);
		if (p/q == r/s) {
			/* Found */
			return (1);
		}
	}

	if (x[1] == y[1] && x[0] < y[0]) {
		p = to_digit(y[0]);
		q = to_digit(x[0]);
		if (p/q == r/s) {
			/* Found */
			return (1);
		}
	}
	return (0);
}

int
main()
{
	int a, b;
	int n = 1, d = 1;

	for (a = 11; a < 50; a++) {
		if (a%10 == 0) {
			continue;
		}
		for (b = a+1; b < 100; b++) {
			if (b%10 == 0) {
				continue;
			}
			if (check_candidate(a, b)) {
				printf("%d, %d\n", a, b);
				n *= a;
				d *= b;
			}
		}
	}
	printf("%d\n", d/n);
	return (0);
}
