#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int
is_prime(uint64_t num)
{
	double t = num;
	uint64_t sq_root = ceil(sqrt(t));
	uint64_t i;

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

void
gen_primes(uint64_t *prime_arr, uint64_t *sum_arr, int limit, int *np)
{
	int k = 0, i;

	prime_arr[k] = 2;
	sum_arr[k] = 2;

	for (i = 3, k = 1; i < limit; i+=2) {
		if (is_prime(i)) {
			prime_arr[k] = i;
			sum_arr[k] = sum_arr[k-1] + i;
			k++;
		}
	}
	*np = k;
}

int
longest_prime_sequence_sum(uint64_t *arr, int np, int limit)
{
	int i, j, max_len = 0;
	uint64_t max_sum = 0, diff;

	for (i = np - 1; i > 0; i--) {
		if (arr[i] < limit && is_prime(arr[i])) {
			if (i+1 > max_len) {
				max_len = i+1;
				max_sum = arr[i];
			}
			continue;
		}
		for (j = 0; j < i; j++) {
			if (i - j + 1 < max_len) {
				break;
			}
			diff = arr[i] - arr[j];
			if (diff >= limit) {
				continue;
			}
			if (is_prime(diff)) {
				if ((i - j + 1) > max_len) {
					max_len = i - j;
					max_sum = diff;
				}
			}
		}
	}
	printf("len - %d sum - %lu\n", max_len, max_sum);
}
		
int
main()
{
	int np, i;
	int limit = 1000000;
	uint64_t *prime_arr, *sum_arr;
	struct timeval t1, t2, t3;
	uint64_t start, end;

	prime_arr = malloc(2 * limit * sizeof(uint64_t));
	if (prime_arr == NULL) {
		perror("malloc");
		exit(1);
	}
	sum_arr = prime_arr + limit;

	gettimeofday(&t1, NULL);
	gen_primes(prime_arr, sum_arr, limit, &np);
	printf("Completed generating primes - %d\n", np);
	gettimeofday(&t2, NULL);
	start = t1.tv_sec * 1000000 + t1.tv_usec;
	end = t2.tv_sec * 1000000 + t2.tv_usec;
	printf("Time for generating primes upto 1000000 - %lu\n", end - start);

	longest_prime_sequence_sum(sum_arr, np, limit);
	gettimeofday(&t3, NULL);
	start = end;
	end = t3.tv_sec * 1000000 + t3.tv_usec;
	printf("Time for finding longest sequence sum - %lu\n", end - start);
	return (0);
}
