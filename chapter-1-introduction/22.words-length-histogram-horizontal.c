#include <stdio.h>

#define IN	0
#define OUT 1

main()
{
	int state;
	int length, max;
	int count[999];
	int i, c, j;

	length = 0;
	max = 0;
	state = OUT;

	for (i = 0; i < 999; ++i)
		count[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;

			if (length > max)
				max = length;

			if (length != 0)
				count[length]++;
			length = 0;
		} else if (state == OUT) {
			state = IN;
			length++;
		} else {
			length++;
		}
	}

	for (i = 0; i < max + 1; ++i) {
		printf("%2d: ", i);
		for (j = 0; j < count[i]; ++j) {
			putchar('#');
		}
		printf("\n");
	}
}
