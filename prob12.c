#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int a[1000][2] = {0};
int
main()
{
	uint32_t num, sq_root, i, j, count;
	uint64_t tri_num;

	for (num = 500; num < -1; num++) { 
		tri_num = (num * (num + 1)) / 2;
		sq_root = ceil(sqrt(tri_num));
		count = 0;
		memset(a, 0, 2000 * sizeof(int));

		for (i = 1, j = 0; i <= sq_root; i++) {
			if (tri_num % i == 0) {
				a[j][0] = i;
				a[j][1] = tri_num / i;
				count += 2;
				j++;
			}
		}

		if (count > 500) {
			for (i = 0; i < j; i++) {
				printf("(%d,%d) ", a[i][0], a[i][1]);
			}
			printf("\n\n%u, %lu\n\n", num, tri_num);
			break;
		}
	}

	return (0);
}
