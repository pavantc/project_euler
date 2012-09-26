#include <stdio.h>
#include <stdlib.h>

#define P(x) (x*(3*x - 1)/2)

int *penta_arr;
int parr_len;

void
gen_penta(int limit)
{
	int i;

	penta_arr = malloc(limit * sizeof(int));

	if (penta_arr == NULL) {
		perror("malloc");
		exit(1);
	}

	parr_len = limit;
	for (i = 1; i < limit; i++) {
		penta_arr[i] = P(i);
	}
}

int
is_penta(int x)
{
	int s = 0, e = parr_len - 1, mid;

	while (s <= e) {
		mid = (s + e) / 2;
		if (x == penta_arr[mid]) {
			return (1);
		}
		if (x < penta_arr[mid]) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return (0);
}

int
main()
{
	int i, j, pi, pj, sum, diff;
	int limit = 10000;

	gen_penta(limit);

	for (i = limit/2; i > 1; i--) {
		for (j = i - 1; j > 1; j--) {
			pi = penta_arr[i];
			pj = penta_arr[j];

			sum = pi + pj;
			diff = pi - pj;
			if (diff < 0) {
				diff = diff * -1;
			}

			if (is_penta(sum) && is_penta(diff)) {
				printf("%d %d %d %d\n", i, j, sum, diff);
				break;
			}
		}
	}
	return (0);
}
