#include <stdio.h>
#include <stdlib.h>

int
main()
{
	FILE *fp;
	int buf[2048];
	int key[3];
	int mk[3];
	int i, j, k, v;
	int n, c, fail, max = 0, pc, sum;

	fp = fopen("cipher1.txt", "r+");

	if (fp == NULL) {
		perror("fopen");
		exit(1);
	}

	n = 0;
	while (fscanf(fp, "%d,", &buf[n++]) != EOF) {
		;
	}
	n--;

	for (i = 'a'; i <= 'z'; i++) {
		for (j = 'a'; j <= 'z'; j++) {
			for (k = 'a'; k <= 'z'; k++) {
				fail = 0;
				pc = 0;
				key[0] = i;
				key[1] = j;
				key[2] = k;
				for (c = 0; c < n; c++) {
					v = buf[c] ^ key[c%3];
					if (!isprint(v)) {
						fail = 1;
						break;
					}
					if (isalnum(v) || isspace(v) || v ==
					    '.') {
						pc++;
					}
				}
				if (fail) {
					continue;
				} else {
					if (max < pc) {
						max = pc;
						mk[0] = i;
						mk[1] = j;
						mk[2] = k;
					}
				}
			}
		}
				
	}

	printf("probable key - %c%c%c\n", mk[0], mk[1], mk[2]);
	printf("probable string:\n");
	sum = 0;
	for (c = 0; c < n; c++) {
		v = buf[c] ^ mk[c%3];
		putc(v, stdout);
		sum += v;
	}
	printf("\nsum: %d\n", sum);
	return (0);
}
