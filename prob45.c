#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define T(x) (((uint64_t)x*(x+1))/2)

int
is_penta(uint64_t tn)
{
	double a, b, c, d;
	uint64_t p;

	a = tn * 24;
	a = a + 1;

	b = sqrt(a);
	c = b*b;

	p = floor(sqrt(a));
	d = p*p;
	
	if (c == d) {
		/* Integral root */
		p = p + 1;

		/* Divisibility test for 6 */
		if (!(p & 1) && !(p % 3)) {
			return (1);
		}
	}
	return (0);
}

/*
 * T(n) = n*(n+1)/2
 * P(m) = m*(3m-1)/2
 * H(k) = k*(2k-1)
 *
 * If T(n) == P(m) == H(k), it is easy to see that k=(n+1)/2
 * So, for all odd n, we have a corresponding H(k) where k = (n+1)/2
 *
 * We now have to find m where T(n) == P(m) and n is odd.
 * One way of doing this is to verify for all T(n), where n is odd, if T(n) is
 * also pentagonal.
 * Given,
 * 	  T(n) = m(3*m - 1)/2
 *   => 2*T(n) = 3m^2 - m
 *   => 3m^2 - m - 2T(n) = 0   
 * 
 * Solving the above quadratic equation for integral m using:
 * m = (-b +/- sqrt(b^2 - 4ac))/2a, where
 * a = 3, b = -1, c = -2T(n), we get the required value of m
 *
 * m = [ -(-1) +/- sqrt((-1)^2 - 4*3*(-2T(n)) ] / 2(3)
 * m = [ 1 + sqrt(1 + 24T(n)) ] / 6
 * We can ignore the second root since it turns out to be a negative number
 */
int
main()
{
	int n;
	uint64_t tn;

	for (n = 3; ;n += 2) {
		tn = T(n);
		if (is_penta(tn)) {
			if (tn == 40755) {
				continue;
			}
			printf("n-%d T(n)-%lu\n", n, tn);
			break;
		}
	}

	return (0);
}
