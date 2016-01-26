#include <stdio.h>

/* Exercise 1-13 horizontal
 * Write a program to print a histogram of the lengths
 * of words in its input. It is easy to draw the histogram
 * with the bars horizontal; a vertical orientation is more
 * challenging. */
#define IN 1	/* inside a word */
#define OUT 0	/* outside a word */

main()
{
	int c, wordLength, state;
	int lengthCount[30];

	wordLength = 0;
	state = OUT;
	
	int i;
	for (i = 0; i < 30; ++i)
		lengthCount[i] = 0;

	while( (c = getchar()) != EOF)
	{
		if ( c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
			if ( wordLength != 0)
			{
				++lengthCount[--wordLength];
				wordLength = 0;
			}
		}
		else if (state == OUT)
		{
			state = IN;
			++wordLength;
		}
		else
		{
			++wordLength;
		}
	}

	printf("  ");
	for (i = 1; i <= 30; ++i)
		printf("%2d ", i);
	putchar('\n');

	int j;
	for (i = 0; i < 30; ++i)
	{
		printf("%2d:", i+1);
		for (j = 0; j < lengthCount[i]; ++j)
			printf("-  ");
		putchar('\n');
	}
}
