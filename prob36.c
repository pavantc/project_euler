#include <stdio.h>
#include <string.h>

char a[8], b[32];

void
to_base2(int num, char res[])
{
	int ind = 0;
	while (num) {
		res[ind++] = '0' + (num & 1);
		num >>= 1;
	}
	res[ind] = '\0';
}

int
is_palindrome(char a[])
{
	int l = strlen(a), i, j;

	for (i = 0, j = (l - 1); i <= j; i++, j--) {
		if (a[i] != (a[j])) {
			return (0);
		}
	}
	return (1);
}

int
main()
{
	int i, sum = 0;
	for (i = 1; i < 1000000; i++) {
		sprintf(a, "%d", i);
		if (is_palindrome(a)) {
			to_base2(i, b);
			if (is_palindrome(b)) {
				sum += i;
			}
		}
	}
	printf("%d\n", sum);
	return (0);
}
