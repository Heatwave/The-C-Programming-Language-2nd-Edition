#include <stdio.h>
#define MINLINE 80
#define MAXLINE 1000

/* Exercise 1-17
 * Write a program to print all input lines that are longer than 80
 * characters. */

main()
{
	char line[MAXLINE];	/* current input line */

	int c, i;
	
	i = 0;
	while ( (c = getchar()) != EOF)
	{
		if ( i < MAXLINE )
		{
			line[i] = c;
			if ( c == '\n')
			{
				if ( i >= 80)
				{
					if ( i + 1 >= MAXLINE)
					{
						line[i-1] = '\n';
						line[i] = '\0';
					}
					else
					{
						line[i+1] = '\0';
					}
					printf("%s", line);
				}
				i = 0;
			}
			else
				++i;
		}
		else
		{
			if ( c == '\n')
			{
				i = 0;
				line[MAXLINE-2] = '\n';
				line[MAXLINE-1] = '\0';
				printf("%s", line);
			}
		}
	}
}
