#include <stdio.h>

/* Exercise 1-13 vertical
 * Write a program to print a histogram of the lengths
 * of words in its input. It is easy to draw the histogram
 * with the bars horizontal; a vertical orientation is more
 * challenging. */

#define IN 1	/* inside a word */
#define OUT 0	/* outside a word */

#define MAXLENGTH 30

main()
{
	int c, wordLength, state;
	int lengthCount[MAXLENGTH];

	wordLength = 0;
	state = OUT;
	
	int i;
	for (i = 0; i < MAXLENGTH; ++i)
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

	int maxLength = lengthCount[0];
	for (i = 0; i < MAXLENGTH - 1; ++i)
		maxLength = maxLength > lengthCount[i] ? maxLength : lengthCount[i];

	for(i = maxLength; i > 0; --i)
	{
		printf("%2d ", i);
		int j;
		for(j = 0; j < MAXLENGTH; ++j)
			if(lengthCount[j] >= i)
				printf("*  ");
			else
				printf("   ");
		putchar('\n');
	}

	for(i = 0; i < 90; ++i)
		putchar('-');

	printf("\n  ");
	
	for(i = 1; i <= MAXLENGTH; ++i)
		printf("%2d ", i);
	putchar('\n');
}
