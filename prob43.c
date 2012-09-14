#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char copy[11];
int prime_num_arr[] = {2, 3, 5, 7, 11, 13, 17};

int64_t sum = 0;

int
is_special_div_prop(char *str)
{
	int i;
	char *p = &str[1];
	int num;

	for (i = 0; i < 7; i++) {
		num = (p[0] - '0') * 100;
		num += (p[1] - '0') * 10;
		num += (p[2] - '0');
		if (num % prime_num_arr[i]) {
			return (0);
		}
		p++;
	}
	return (1);
}

void __attribute__((always_inline))
swap(char *a, char *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/*
 * The recursive algorithm below does the following:
 * Lets take the letter combination - abc
 *
 * It starts off by producing all possible permutations starting with 'a'.
 * This is done by keeping 'a' unchanged and calling get_all_permutations
 * (recursively) with an advanced pointer (p+1). Note that the changes are being
 * done in-place and hence the input string is getting modified with each swap.
 * So, at the end of all iterations, get_all_permutations() makes sure that it
 * returns the input string to its initial state.
 *
 * In the above example, the following is the call stack():
 * We use the short form g_a_c() to represent get_all_permutations().
 * g_a_c(abc, 3)
 *   g_a_c(bc, 2)
 *     g_a_c(c, 1) -> Print 'abc'
 *   i is 0 here, which is less than (len - 1) => (2 - 1)
 *   swap elem0 with elem1 => b with c. String becomes cb
 *   g_a_c(cb, 2)
 *     g_a_c(b, 1) -> Print 'acb'
 *   i is 1 here which is NOT less than (2 - 1). Time to restore the string to
 *   its original position
 *   Rotate the current string to the left once to get back to the initial
 *   state.
 *   String no becomes 'bc'.
 *
 * After all the permutations starting with 'a', it brings the next letter in
 * the input string to the 0th place by swapping it with what was there
 * already. In this case, 'b' is swapped with 'a'. Now, the string becomes
 * 'bac'. It agains gets all permutations starting with 'b'. This way, it goes
 * all the way until all the for the last letter is obtained.
 */

void
get_all_permutations(char *p, int len)
{
	int i, t;

	if (len == 1) {
		if (is_special_div_prop(copy)) {
			sum += atoll(copy);
		}
		return;
	}
	for (i = 0; i < len; i++) {
		get_all_permutations(p+1, len - 1);
		/*
		 * Bring the next letter to position 0. get_all_permutations()
		 * starting with that letter.
		 */
		if (i < len - 1) {
			swap(&p[0], &p[i+1]);
		} else {
			/*
			 * Indicates completion of all permutations. Time to
			 * restore the string to its initial state. If the
			 * initial string was "abcde", at this point, due to 4
			 * swaps, (not 5, since we are in the fifth iteration)
			 * the string would be - "eabcd". We restore initial
			 * condition by doing a rotate_left_once.
			 */
			for (i = 0; i < len - 1; i++) {
				swap(&p[i], &p[i+1]);
			}
		}
	}
}

int
main()
{
	int i;
	char a[11] = "0123456789";

	strcpy(copy, a);
	get_all_permutations(&copy[0], 10);
	printf("%ld\n", sum);

	return (0);
}
