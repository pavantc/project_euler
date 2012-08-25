#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int
main()
{
	uint64_t sum = 0;
	int num1 = 0, num2 = 1, next;

	while (1) {
		next = num1 + num2;
		num1 = num2;
		num2 = next;

		if ((num1 & 0x1) == 0) {
			sum += num1;
		}

		if (num2 > 4000000) {
			break;
		}
	}

	printf("sum : %lu\n", sum);
	return (0);
}
