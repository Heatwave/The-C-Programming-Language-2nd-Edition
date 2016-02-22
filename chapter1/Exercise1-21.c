#include <stdio.h>

/* Exercise 1-21
 * Write a program entab that replaces strings of blanks by the
 * minumum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab. When either a tab or
 * a single blank would suffice to reach a tab stop, which 
 * should be given preference?
 */

#define MAXLINE 10000

main()
{
	int tabstop;

	char line[MAXLINE];

	int c, i, blankCount;

	tabstop = 4;

	i = 0;
	
	blankCount = 0;
	

	while ((c = getchar()) != EOF)
	{
		line[i] = c;
		if (c == ' ')
			++blankCount;
		if (c != ' ')
			blankCount = 0;

		if (blankCount >= tabstop)
		{
			i = i - tabstop + 1;
			line[i] = '\t';
			blankCount = 0;
		}
		++i;

		if (c == '\n')
		{
			line[i] = '\0';
			printf("%s", line);
			i = 0;
		}
	}
}
