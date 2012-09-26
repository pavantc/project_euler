#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct prime_factor {
	int factor;
	int count;
} pf_t;

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

int rep_div(int *num, int div)
{
	int c = 0, k = *num;
	while (k % div == 0) {
		k /= div;
		c++;
	}
	*num = k;
	return (c);
}

int
validate_and_add(pf_t *pf_arr, int f, int c, int ind)
{
	int i;

	for (i = 0; i < ind; i++) {
		if ((f == pf_arr[i].factor) && (c == pf_arr[i].count)) {
			return (1);
		}
	}
	pf_arr[ind].factor = f;
	pf_arr[ind].count = c;
	return (0);
}

int
prime_factorize(pf_t *pf_arr, int num, int extent,
    int factor_count, int *index)
{
	int fc = 0, c, d, r;
	int ind = *index;

	if ((num & 1) == 0) {
		/* Even. Special run for the only even prime */
		c = rep_div(&num, 2);
		if (validate_and_add(pf_arr, 2, c, ind)) {
			return (fc);
		} else {
			fc++;
			ind++;
		}
	}

	for (d = 3; (d <= num) && (fc <= factor_count); d+=2) {
		if (is_prime(num)) {
			if (validate_and_add(pf_arr, num, 1, ind)) {
				break;
			} else {
				fc++;
				ind++;
			}
			break;
		}
		if (!is_prime(d)) {
			continue;
		}
		if (c = rep_div(&num, d)) {
			/* Got a prime factor */
			if (fc == factor_count) {
				/*
				 * If there are more prime factors than we
				 * desire, we fail. Do not add to list
				 */
				fc++;
				break;
			}
			if (validate_and_add(pf_arr, d, c, ind)) {
				break;
			} else {
				fc++;
				ind++;
			}
		}
	}
	*index = ind;
	return (fc);
}

int
main()
{
	int i, c, arr_len;
	int fc = 0, index;
	int extent = 4, factor_count = 4;
	pf_t *pf_arr;

	arr_len = extent * factor_count;

	pf_arr = malloc(arr_len * sizeof(struct prime_factor));
	if (pf_arr == NULL) {
		fprintf(stderr, "Memory allocation failed for prime factor "
		    "array\n");
		exit(1);
	}
	for (i = 1; ; i++) {
		memset(pf_arr, 0, arr_len * sizeof(struct prime_factor));
		index = 0;
		for (c = 0; c < extent; c++) {
			fc = prime_factorize(pf_arr, i + c, extent,
			    factor_count, &index);
			if (fc != factor_count) {
				break;
			}
		}

		if (c == extent) {
			int j, k, l;
			for (k = 0; k < extent; k++) {
				printf("%d -\n", i+k);
				for (j = 0; j < factor_count; j++) {
					l = k*extent + j;
					printf("(%d^%d) ", pf_arr[l].factor,
					pf_arr[l].count);
				}
				printf("\n");
			}
			break;
		} else {
			i = i + c;
		}
	}
	free(pf_arr);

	return (0);
}
