#include <stdio.h>

/* Exercise 1-8
 * Write a program to count blanks, tabs and newlines. */

main()
{
	int c, blanks, tabs, newlines;

	blanks = 0;
	tabs = 0;
	newlines = 0;
	
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
			++newlines;
		if (c == '\t')
			++tabs;
		if (c == ' ')
			++blanks;
	}
	printf("Blanks: %d\nTabs: %d\nNewLines: %d\n", blanks, tabs, newlines);
}
