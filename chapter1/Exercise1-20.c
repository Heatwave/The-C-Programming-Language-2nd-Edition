#include <stdio.h>

/* Exercise 1-20
 * Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next
 * tab stop. Assume a fixed set of tab stops, say every n
 * columns. Should n be a variable or a symbolic parameter? */

#define MAXLINE 1000

main()
{
	int tabstop;

	char line[MAXLINE];

	int c, i, j;

	tabstop = 4;

	i = 0;

	while ((c = getchar()) != EOF)
	{
		line[i] = c;
		if (c == '\t')
		{
			for (j = 0; j < tabstop; ++i, ++j)
				line[i] = ' ';
		}
		else
			++i;

		if (c == '\n')
		{
			line[i] = '\0';
			printf("%s", line);
			i = 0;
		}
	}
}
