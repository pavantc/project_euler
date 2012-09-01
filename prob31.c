#include <stdio.h>

int coins[] = {200, 100, 50, 20, 10, 5, 2, 1};
int nc[] = {1, 2, 4, 10, 20, 40, 100, 200};
int count = 0;

int
find_combs(int i, int rem_sum)
{
	int c, s;

	if (i == 9) {
		return (1);
	}
	if (rem_sum < 0) {
		return (1);
	}
	if (rem_sum == 0) {
		count++;
		return (1);
	}
	for (c = 0; c <= nc[i]; c++) {
		if (find_combs(i+1, rem_sum - c*coins[i])) {
			break;
		}
	}
	return (0);
}

int
main()
{
	find_combs(0, 200);
	printf("%d\n", count);
	return (0);
}
