#include <stdio.h>

/* Exercise 1-9
 * Write a program to copy its input to output,
 * replacing each string of one or more blanks 
 * by a single blank. */

main()
{
	int pre, next;

	while( (next = getchar()) != EOF)
	{
		if ( next != ' ' || pre != ' ')
			putchar(next);
		pre = next;
	}
}
