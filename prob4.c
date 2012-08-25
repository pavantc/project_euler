#include <stdio.h>
#include <string.h>

int
is_palindrome(char a[])
{
	int i, j, len;
	len = strlen(a);

	for (i = 0, j = len - 1; i < j; i++, j--) {
		if (a[i] != a[j]) {
			return (0);
		}
	}
	return (1);
}

int
main()
{
	int i, j, product, max = 0;
	char a[16] = {0, };

	for (i = 999; i > 100; i--) {
		if ((i % 10) == 0) {
			continue;
		}
		for (j = i; j > 100; j--) {
			if ((j % 10) == 0) {
				continue;
			}
			product = i * j;
			sprintf(a, "%d", product);
			if (is_palindrome(a)) {
				if (product > max) {
					max = product;
				}
			}
		}
	}

	printf("%d\n", max);
	return (0);
}
