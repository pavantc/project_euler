#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct card {
	int val, suit;
} card_t;

enum {
	LVL_ERROR = 0,
	LVL_INFO,
	LVL_DEBUG,
	LVL_MAX
};

int cur_dbg_lvl = LVL_MAX;

#define ERRLOG(lvl, msg...) \
do {\
	if (lvl >= cur_dbg_lvl) printf(msg); \
} while(0);

void
invalidate_hand(card_t *hand, int card, int count)
{
	int i;

	for (i = 0; i < 5; i++) {
		if (hand[i].val == card) {
			hand[i].val = -1;
			count--;
		}
	}
	if (count != 0) {
		ERRLOG(LVL_MAX, "Invalidate_hand: Unexpected count - %d for "
		    "card %d\n", count, card);
	}
}

void
sort(card_t *hand)
{
	int i, j;
	card_t temp;

	for (i = 1; i < 5; i++) {
		for (j = 0; j < i; j++) {
			if (hand[j].val > hand[i].val) {
				temp = hand[j];
				hand[j] = hand[i];
				hand[i] = temp;
			}
		}
	}
}

int
get_hand_rank(card_t *hand, int *rank, int *val)
{
	int cardc[13] = {0, };
	int suitc[4] = {0, };
	int maxc = 0, maxs = 0, rem = 0;
	int maxv = 0, maxcc = 0;
	int i;

	for (i = 0; i < 5; i++) {
		if (hand[i].val == -1) {
			continue;
		}
		rem = 1;
		cardc[hand[i].val]++;
		suitc[hand[i].suit]++;

		if (suitc[hand[i].suit] > maxs) {
			maxs = suitc[hand[i].suit];
		}
		if (hand[i].val > maxv) {
			maxv = hand[i].val;
		}
		if (cardc[hand[i].val] > maxc) {
			maxc = cardc[hand[i].val];
			maxcc = hand[i].val;
		}
	}

	if (!rem) {
		return (1);
	}

	if (maxs == 5) {
		/* Flush/Royal Flush/Straight Flush */
		int i, contig = 1;

		*rank = 6;

		sort(hand);
		for (i = 0; i < 4; i++) {
			if (hand[i+1].val != (hand[i].val + 1)) {
				contig = 0;
				break;
			}
		}

		if (contig) {
			/* Straight Flush */
			*rank = 9;
			if (maxv == 12) {
				/* Royal Flush */
				*rank = 10;
			}
		}
		*val = maxv;

		for (i = 0; i < 5; i++) {
			hand[i].val = -1;
		}

		return (0);
	}
	
	if (maxc == 1) {
		/* Straight/High card */

		int i, contig = 1;

		sort(hand);
		for (i = 0; i < 4; i++) {
			if (hand[i+1].val != (hand[i].val + 1)) {
				contig = 0;
				break;
			}
		}

		if (contig) {
			/* Straight */
			*rank = 5;
			for (i = 0; i < 5; i++) {
				hand[i].val = -1;
			}
		} else {
			*rank = 1;
			ERRLOG(LVL_INFO, "Calling invalidate hand for Highest "
			    "card %d\n", maxv);
			invalidate_hand(hand, maxv, 1);
		}
		*val = maxv;

		return (0);
	}

	if (maxc == 4) {
		/* Four of a kind */
		*rank = 8;
		*val = maxcc;
		ERRLOG(LVL_INFO, "Calling invalidate hand for four of a kind\n");
		invalidate_hand(hand, maxcc, 4);
		return (0);
	}
	if (maxc == 3) {
		/* Full house/Three of a kind */
		int fh = 0;
		*val = maxcc;
		ERRLOG(LVL_INFO, "Calling invalidate hand for three of a kind\n");
		invalidate_hand(hand, maxcc, 3);
		for (i = 12; i > 0; i--) {
			if (cardc[i] == 2) {
				fh = 1;
				ERRLOG(LVL_INFO, "Calling invalidate hand for Full House\n");
				invalidate_hand(hand, i, 2);
				break;
			}
		}
		if (fh) {
			*rank = 7;
		} else {
			*rank = 4;
		}
		return (0);
	}
	if (maxc == 2) {
		int pc = 0;

		/*
		 * Two pairs/One pair
		 * We need to find the card with the highest value. So start
		 * looking at the cardc array from the higest value.
		 */

		*val = -1;
		for (i = 12; i > 0; i--) {
			if (cardc[i] == 2) {
				pc++;
				if (*val < i) {
					*val = i;
				}
				ERRLOG(LVL_INFO, "Calling invalidate hand for pair\n");
				invalidate_hand(hand, i, 2);
			}
		}
		if (pc == 2) {
			*rank = 3;
		} else {
			*rank = 2;
		}
		return (0);
	}
	return (1);
}

int
to_val(int c)
{
	switch(c) {
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return (c - '0' - 2);
	case 'T':
		return 8;
	case 'J':
		return 9;
	case 'Q':
		return 10;
	case 'K':
		return 11;
	case 'A':
		return 12;
	}
	return (-1);
}
		
int
to_suit(int c)
{
	switch(c) {
	case 'S':
		return 0;
	case 'D':
		return 1;
	case 'H':
		return 2;
	case 'C':
		return 3;
	}
}

int
read_hands(char *input, card_t *h1, card_t *h2)
{
	int i = 0, k = 0;

	if (strlen(input) < 29) {
		return (1);
	}

	while (k < 5) {
		h1[k].val = to_val(input[i]);
		h1[k].suit = to_suit(input[i+1]);
		i+=3;
		k++;
	}
	k = 0;
	while (k < 5) {
		h2[k].val = to_val(input[i]);
		h2[k].suit = to_suit(input[i+1]);
		i+=3;
		k++;
	}
	return (0);
}

int
main()
{
	card_t p1h[5], p2h[5];
	int p1r, p2r, p1v, p2v;
	int ind1, ind2, c1, c2;
	char input[80];
	FILE *fp;
	int i, a, b, done;
	int count = 0;

	fp = fopen("poker.txt", "r+");
	if (fp == NULL) {
		perror("fopen");
		exit(1);
	}

	while (fgets(input, 79, fp) != NULL) {
		if (read_hands(input, p1h, p2h)) {
			ERRLOG(LVL_MAX, "Error in input. Aborting...\n");
			exit(1);
		}

		for (i = 0; i < 5; i++) {
			ERRLOG(LVL_INFO, "%d - %d\n", p1h[i].val, p2h[i].val);
		}

		done = 0;
		while (!done) {
			a = get_hand_rank(p1h, &p1r, &p1v);
			b = get_hand_rank(p2h, &p2r, &p2v);

			if (a && b) {
				break;
			}

			if (p1r > p2r) {
				ERRLOG(LVL_INFO, "p1r = %d, p2r = %d, Player 1 wins\n", p1r, p2r);
				done = 1;
				count++;
			} else if (p1r < p2r) {
				ERRLOG(LVL_INFO, "p1r = %d, p2r = %d, Player 2 wins\n", p1r, p2r);
				done = 1;
			} else {
				/* Tie. Check values */
				if (p1v > p2v) {
					ERRLOG(LVL_INFO, "p1v = %d, p2v = %d, Player 1 wins\n", p1v, p2v);
					done = 1;
					count++;
				} else if (p1v < p2v) {
					ERRLOG(LVL_INFO, "p1v = %d, p2v = %d, Player 2 wins\n", p1v, p2v);
					done = 1;
				}
			}
		}
		if (!done) {
			ERRLOG(LVL_INFO, "Match draw\n");
		}
	}

	ERRLOG(LVL_MAX, "Player 1 wins %d hands.\n", count);

	return (0);
}
