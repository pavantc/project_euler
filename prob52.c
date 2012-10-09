#include <stdio.h>

#define SIZE 10

int
get_digits(int *arr, int num)
{
	int i = 0;
	while(num) {
		arr[i++] = num%10;
		num /= 10;
	}
	return (i);
}

int
same_digits(int *a, int *b, int len)
{
	int temp[SIZE], i, j;

	for (i = 0; i < len; i++) {
		temp[i] = a[i];
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			if (b[i] == temp[j]) {
				temp[j] = -1;
				break;
			}
		}
	}
	for (i = 0; i < len; i++) {
		if (temp[i] != -1) {
			return (0);
		}
	}

	return (1);
}

int
is_candidate(int num)
{
	int a[SIZE], b[SIZE];
	int i, k, l1, l2;

	l1 = get_digits(a, num);
	k = num;
	for (i = 0; i < 5; i++) {
		k += num;
		l2 = get_digits(b, k);
		if (l1 != l2) {
			return (0);
		}
		if (!same_digits(a, b, l1)) {
			return (0);
		}
	}
	return (1);
}

int
main()
{
	int i;
	for (i = 1; ; i++) {
		if (is_candidate(i)) {
			printf("%d\n", i);
			break;
		}
	}
	return (0);
}
