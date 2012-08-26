#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int
is_prime(int num)
{
	double t = abs(num);
	int sq_root = ceil(sqrt(t));
	int i;

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
	int n, a, b, p;
	int ma, mb, mn = 0;

	for (a = -999; a < 1000; a++) {
		for (b = -999; b < 1000; b++) {
			for (n = 0; n < 100; n++) {
				p = n * n + a * n + b;
				if (p < 0) {
					p *= -1;
				}
				if (!is_prime(p)) {
					break;
				}
			}
			if (n > mn) {
				mn = n;
				ma = a;
				mb = b;
			}
		}
	}
	printf("%d %d %d %d\n", mn, ma, mb, ma * mb);
	return (0);
}
