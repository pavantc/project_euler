#include <stdio.h>
#include <stdlib.h>

#define P(x) (x*(3*x - 1)/2)

int *
gen_penta(int limit)
{
	int i;
	int *penta_arr;

	penta_arr = malloc(limit * sizeof(int));

	if (penta_arr == NULL) {
		perror("malloc");
		exit(1);
	}

	for (i = 1; i < limit; i++) {
		penta_arr[i] = P(i);
	}
	return (penta_arr);
}

int
binary_search(int x, int *arr, int len)
{
	int s = 0, e = len - 1, mid;

	while (s <= e) {
		mid = (s + e) / 2;
		if (x == arr[mid]) {
			return (1);
		}
		if (x < arr[mid]) {
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
	/*
	 * Limit arrived at by trial and error, starting from 10 and
	 * increasing it by a factor of 10 every time.
	 * Need a better way to determine it.
	 */
	int limit, found = 0;
	int *penta_arr;
	int parr_len;


	for (limit = 10; !found && limit < 1000000; limit *= 10) {
		penta_arr = gen_penta(limit);
		for (i = limit/2; !found && i > 1; i--) {
			for (j = i - 1; j > 1; j--) {
				pi = penta_arr[i];
				pj = penta_arr[j];

				sum = pi + pj;
				diff = pi - pj;
				if (diff < 0) {
					diff = diff * -1;
				}

				if (binary_search(sum, penta_arr, limit) &&
				    binary_search(diff, penta_arr, limit)) {
					printf("i=%d j=%d\nP(i)+P(j)=%d\n"
					    "P(i)-P(j)=%d\n", i, j, sum, diff);
					found = 1;
					break;
				}
			}
		}
		free(penta_arr);
	}
	return (0);
}
