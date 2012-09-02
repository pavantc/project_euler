#include <stdio.h>

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int
fact(int n)
{
	int p = 1;
	while (n > 1) {
		p *= n;
		n--;
	}
	return (p);
}

int
print_digit(int n)
{
	int i = 0, k = -1;

	for (i = 0; i < 10; i++) {
		if (a[i] != -1) {
			k++;
		}
		if (k == n) {
			break;
		}
	}
	printf("%d", a[i]);
	a[i] = -1;
}

int
main()
{
	/*
	 * To get the millionth permutation, we start with (million - 1)
	 * We have 10 digits. The total number of permutations with 10 digits
	 * will be 10! which is > 1 million.
	 * So, we keep the most significant digit out of the game and start
	 * with 9 digits. The number of permutations with 9 digits = 9! =
	 * 362880. This is less than a million. With 0 as the first most
	 * significant digit, we can get 9! permutations. With 1 as the first
	 * digit, we can get another 9! permutations. That leaves us at
	 * permutation number 725760. Another complete set with 2 as the first
	 * digit will take us to (725760 + 362880) which is beyond a million.
	 * Hence, for the millionth lexicographic permutation, 2 is the first
	 * digit. This number is an index into the available digits array. It
	 * can also be obtained by doing an integer division of the remaining
	 * permutations with the factorial of the remaining digits.
	 * i.e. - 999999/9! = 2.XYZ. We consider only the integer part of the
	 * division - 2, which becomes the index into the initial array -
	 * { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
	 * The digit at index 2 is '2' (starting the count from 0)
	 * So, 2 is the first digit of the millionth lexicographic permutation.
	 *
	 * With 2 out of the picture, we have 9 digits -
	 * 0, 1, 3, 4, 5, 6, 7, 8, 9.
	 * And, we have (999999 mod 9!) number of permuations left to get to
	 * the millionth.
	 * Following a similar logic as above for the rest, we get to the final
	 * number.
	 */
	int num = 999999;
	int i, s = 9, c = 0;

	while (num) {
		i = num/fact(s);
		num = num % fact(s);
		print_digit(i);
		s--;
		c++;
	}

	for (s = 0; s < 10; s++) {
		if (a[s] != -1) {
			printf("%d", a[s]);
		}
	}
	printf("\n");

	return (0);
}
