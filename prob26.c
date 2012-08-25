#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct substr {
	char *a;
	int ind;
	int len;
};

struct substr arr[10] = {
	{0, 0, 0},
};

char a[1000][2048];

void
read_input()
{
	FILE *fp;
	int i;

	fp = fopen("prob26.input", "r+");
	if (fp == NULL) {
		perror("fopen");
		exit(1);
	}
	for(i = 0; i < 1000; i++) {
		fgets(&a[i][0], 2048, fp);
		a[i][2000] = 0;
	}
	fclose(fp);
}

int
main()
{
	char *s, *d, *p;
	struct substr *sp;
	int t, i, j, k, digit;
	int max = 0, fmax = 0;

	read_input();

	for (k = 0; k < 1000; k++) {
		p = &a[k][0];
		memset(arr, 0, sizeof(struct substr) * 10);
		for (i = 0; i < strlen(p); i++) {
			digit = p[i] - '0';
			sp = &arr[digit];
			if (sp->a == 0) {
				sp->a = &p[i];
				sp->ind = i;
			} else {
				t = i - sp->ind;
				s = sp->a;
				d = &p[i];
				while((*s++ == *d++) && --t)
					;
				if (!t) {
					sp->a = &p[i];
					sp->len = i - sp->ind;
					sp->ind = i;
				}
			}
		}
		max = 0;
		for (i = 0; i < 10; i++) {
			if (arr[i].len > max) {
				max = arr[i].len;
			}
		}

		if (max > fmax) {
			fmax = max;
		}
	}
	printf("Longest recurrance for iteration - %d\n", fmax+1);

	return (0);
}
