#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int
is_prime(uint64_t num)
{
	double t = num;
	uint64_t sq_root = ceil(sqrt(t));
	uint64_t i;

	if (num <= 1) {
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
num_to_digits(int *digits, int num)
{
	int i = 0;
	while(num) {
		digits[i++] = num % 10;
		num = num/10;
	}
	return (i);
}

int result[10];
int copy[10];
int k;

int
digits_to_num(int *digits, int len)
{
	int f = 1, num = 0, i;

	for (i = 0; i < len; i++) {
		num = num + digits[i] * f;
		f = f*10;
	}

	return (num);
}

int prime_arr[10] = {0, };
int prime_arr_ind = 0;

int
add_to_prime_arr(int num)
{
	int i, fail = 0;

	for (i = 0; i < prime_arr_ind; i++) {
		if (prime_arr[i] == num) {
			fail = 1;
		}
	}
	if (!fail) {
		prime_arr[prime_arr_ind++] = num;
		return (1);
	}
	return (0);
}

void
g_a_c(int *pos_arr, int len, int slen, int *orig_num, int orig_len, int nump)
{
	int i;
	int *p;

	if (slen == 0) {
		int j, l, num, c = 0;

		for (j = 0; j < orig_len; j++) {
			copy[j] = orig_num[j];
		}

		for (l = 1; l <= 9; l++) {
			for (i = 0; i < k; i++) {
				copy[result[i]] = l;
			}
			num = digits_to_num(copy, orig_len);
			if (is_prime(num)) {
				if (add_to_prime_arr(num)) {
					c++;
				}
			}

			if (c == nump) {
				printf("Found: %d\n", prime_arr[0]);
				for (i = 0; i < c; i++) {
					printf("%d ", prime_arr[i]);
				}
				printf("\n");
				exit(0);
			}
		}
			
		prime_arr_ind = 0;
		memset(prime_arr, 10, sizeof(int));
		return;
	}
	for (i = 0, p = pos_arr; i <= len - slen; i++, p++) {
		result[k++] = *p;
		g_a_c(p + 1, len - i - 1, slen - 1, orig_num, orig_len, nump);
		k--;
	}
}

int
try_prime_comb(int num, int nump)
{
	int digits[10];
	int pos_arr[10];
	int i, len;

	len = num_to_digits(digits, num);
	for (i = 0; i < len; i++) {
		pos_arr[i] = i;
	}

	for (i = 1; i < len; i++) {
		g_a_c(pos_arr, len, i, digits, len, nump);
	}
}

int
main()
{
	int i;

	for (i = 11; ; i += 2) {
		if (is_prime(i)) {
			try_prime_comb(i, 8);
		}
	}

	return (0);
}
