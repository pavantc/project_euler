#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void
read_input(int a[][100])
{
	FILE *fp;
	char buf[512], *p;
	int i, j;

	fp = fopen("triangle.txt", "r+");
	if (fp == NULL) {
		perror("fopen");
		exit(1);
	}
	for(i = 0; i < 100; i++) {
		fgets(buf, 512, fp);
		p = strtok(buf, " \n");
		for (j = 0; p && (j <= i); j++) {
			a[i][j] = atoi(p);
			p = strtok(NULL, " \n");
		}
	}
	fclose(fp);
}


int
main()
{
	int a[100][100] = {0, };
	int i, j, ls, rs;

	read_input(a);

	for (i = 98; i >= 0; i--) {
		for (j = 0; j < i+1; j++) {
			ls = a[i][j] + a[i+1][j];
			rs = a[i][j] + a[i+1][j+1];
			a[i][j] = (ls > rs) ? ls : rs;
		}
	}
	printf("%d\n", a[0][0]);

	return (0);
}
