#include <stdio.h>
#include <math.h>

int
is_prime(int num)
{
	double t = num;
	int sq_root = ceil(sqrt(t));
	int i;

	if (num == 1) {
		return (0);
	}

	if (num == 2) {
		return (1);
	}

	for (i = sq_root; i > 1; i--) {
		if (num % i == 0) {
			return (0);
		}
	}
	return (1);
}

int
main()
{
	int i = 1, j = 2;
	int n = 0, d = 1;
	int p, q, r, s;

	while(1) {
		p = i + j;
		q = i + 2*j;
		r = i + 3*j;
		s = i + 4*j;

		if (is_prime(p))
			n++;
		if (is_prime(q))
			n++;
		if (is_prime(r))
			n++;
		if (is_prime(s))
			n++;

		d += 4;
		if (n*100/d < 10) {
			printf("%d\n", j+1);
			break;
		}
		i = s;
		j += 2;
	}
	return (0);
}
