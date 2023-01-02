#include <stdio.h>

#define IN	0
#define OUT 1
#define WORD_MAX_LENGTH 999

main()
{
	int state;
	int length, maxLength, maxCount;
	int count[WORD_MAX_LENGTH];
	int i, c, j;

	length = 0;
	maxLength = 0;
	maxCount = 0;
	state = OUT;

	for (i = 0; i < WORD_MAX_LENGTH; ++i)
		count[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;

			if (length > maxLength)
				maxLength = length;

			if (length != 0)
				count[length]++;

			if (count[length] > maxCount)
				maxCount = count[length];

			length = 0;
		} else if (state == OUT) {
			state = IN;
			length++;
		} else {
			length++;
		}
	}

	for (i = maxCount; i > 0; --i) {
		printf("%2d: ", i);

		for (j = 1; j < maxLength + 1; ++j) {
			printf("  ");
			if (count[j] >= i)
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}

	printf("    ");
	for (i = 1; i < maxLength + 1; ++i)
		printf("%3d", i);

	printf("\n");
}
