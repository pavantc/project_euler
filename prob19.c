#include <stdio.h>

int days_per_month[2][12] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/*
 * Jan 1st 1900 is a Monday => Jan 1st 1901 is a Tuesday.
 * Jan 6th 1901 is a Sunday. Similarly, 13th, 20th and so on are sundays.
 * If the day of the year divided by 7 leaves a remainder of 6, we have a
 * sunday.
 */
int
main()
{
	int fday = 1, sundays = 0;
	int i, j, index, leap_yrs = 0;

	for (i = 1901; i <= 2000; i++) {
		index = ((i % 4) == 0);
		for (j = 0; j < 12; j++) {
			fday += days_per_month[index][j];
			if ((fday % 7) == 6) {
				sundays++;
			}
		}
	}
	printf("%d\n", sundays);
	return (0);
}
