#include <stdio.h>

/* Exercise 1-14
 * Write a program to print a histogram of the frequencies
 * of different characters in its input */

#define MAXLENGTH 52

main()
{
	int c;
	int characters[MAXLENGTH];
	
	int i;
	for (i = 0; i < MAXLENGTH; ++i)
		characters[i] = 0;

	while ( (c = getchar()) != EOF)
	{
		if ( c >= 'a' && c <= 'z')
			++characters[c - 'a'];
		if ( c >= 'A' && c <= 'Z')
			++characters[c - 'A' + 26];
	}

	int maxCount = characters[0];
	for (i = 0; i < MAXLENGTH; ++i)
		maxCount = maxCount > characters[i] ? maxCount : characters[i];

	for (i = maxCount; i > 0; --i)
	{
		printf("%4d ", i);
		int j;
		for (j = 0; j < MAXLENGTH; ++j)
			if (characters[j] >= i)
				printf("* ");
			else
				printf("  ");
		putchar('\n');
	}

	for (i = 0; i < 120; ++i)
		putchar('-');

	printf("\n     ");

	for (i = 'a'; i <= 'z'; ++i)
		printf("%c ", i);

	for (i = 'A'; i <= 'Z'; ++i)
		printf("%c ", i);

	putchar('\n');
}
