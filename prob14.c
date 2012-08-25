#include <stdio.h>
#include <stdint.h>

int
main()
{
	int i, count, max = 0, num;
	uint64_t prod;

	for (i = 2; i < 1000000; i++) {
		prod = i;
		count = 0;
		while (prod != 1) {
			if ((prod & 1) == 0) {
				prod = prod / 2;
			} else {
				prod = 3 * prod + 1;
			}
			count++;
		}
		if (count > max) {
			max = count;
			num = i;
		}
	}
	printf("%d, %d\n", num, count);
}
