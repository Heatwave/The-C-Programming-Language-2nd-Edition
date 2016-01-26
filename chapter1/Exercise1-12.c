#include <stdio.h>

/* Exercise 1-12
 * Write a program that prints its input one word per line. */

main()
{
	int c, pre;

	while ( (c = getchar()) != EOF)
	{
		if ( c == ' ' || c == '\n' || c == '\t')
		{
			if (pre != ' ' && pre != '\n' && pre != '\t')
				putchar('\n');
		}
		else
		{
			putchar(c);
		}
		pre = c;
	}
}
