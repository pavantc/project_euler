#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 * Lazy to write a file sort program. Used the unix sort program to generate
 * n.txt from names.txt
 */
int
main()
{
	FILE *fp;
	int c = 0, s, i;
	uint64_t p = 0;
	char buf[80];

	fp = fopen("n.txt", "r+");
	if (fp == NULL) {
		perror("fopen");
	}

	while(fgets(buf, 80, fp) != NULL) {
		c++;
		s = 0;
		for(i = 0; i < strlen(buf) - 1; i++) {
			s += (buf[i] - 'A' + 1);
		}
		p += s*c;
	}
	printf("%lu\n", p);
	fclose(fp);
	return (0);
}
