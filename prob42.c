#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 * Pre-processing of words.txt:
 * Used vi to replace commas with newline - :%s/,//g
 * Used vi to get rid of the quotes - :%s/"//g
 * Used cut to check the longest word -
 * [1] cat /tmp/words.txt | cut -b14 | grep -v ^$ | wc -l
 * [2] cat /tmp/words.txt | cut -b15 | grep -v ^$ | wc -l
 * [1] resulted in 6 and [2] resulted in 0 telling that the longest word is of
 * 14 letters.
 * From this, one needs to calculate for triangle numbers only upto 26*15, the
 * largest sum that can be formed by a word with 15 letters.
 * [Triangle numbers upto 26*14 should have been enough. Just being paranoid]
 *
 * Finding n corresponding to 26*15:
 * 0.5*n*(n+1) should be greater than 26*15
 * => n^2 + n > 26*30 = 780
 * Solving the quadratic inequality n^2 + n - 780 > 0, we get n = 28
 */

int tnum_arr[30] = {0,};

int
is_triangle_number(int num)
{
	int i;
	for (i = 1; i < 29; i++) {
		if (num == tnum_arr[i]) {
			return (1);
		}
	}
	return (0);
}

int
main()
{
	FILE *fp;
	int c = 0, s, i;
	char buf[80];

	s = 0;
	for (i = 1; i <= 28; i++) {
		s += i;
		tnum_arr[i] = s;
	}

	fp = fopen("words.txt", "r+");
	if (fp == NULL) {
		perror("fopen");
	}

	while(fgets(buf, 80, fp) != NULL) {
		s = 0;
		for(i = 0; i < strlen(buf) - 1; i++) {
			s += (buf[i] - 'A' + 1);
		}
		if (is_triangle_number(s)) {
			c++;
		}
	}
	printf("%d\n", c);
	fclose(fp);
	return (0);
}
