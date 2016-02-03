#include <stdio.h>

/* Exercise 1-18
 * Write a program to remove trailing blanks and tabs
 * from each line of input, and to delete entirely blank lines. */

#define MAXLINE 1000

main()
{
	char line[MAXLINE];	/* current input line */

	int c, i;

	i = 0;

	while ((c = getchar()) != EOF)
	{
		line[i] = c;
		if ( c == '\n')
		{
			if (i != 0)
			{
				while (line[i-1] == ' ' || line[i-1] == '\t')
				{
					line[i-1] = line[i];
					--i;
				}
				line[i+1] = '\0';
				printf("%s", line);
				i = 0;
			}
			else
			{
				i = 0;
			}
		}
		else
			++i;
	}
}
