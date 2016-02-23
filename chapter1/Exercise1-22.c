#include <stdio.h>

/* Exercise 1-22
 * Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs
 * before the n-th column of input. Make sure your program does
 * something intelligent with very long lines, and if there are
 * no blanks or tabs before the specified column.
 */

#define MAXLINE 10000

void copy(char to[], char from[]);

main()
{
	int tabstop;

	char line[MAXLINE];

	char tempLine[MAXLINE];

	int lineLimit = 80;

	int c, i, j, k;

	i = 0;

	while ((c = getchar()) != EOF)
	{
		line[i] = c;

		if (i == lineLimit)
		{
			if (line[i] == '\n')
			{
				line[i+1] = '\0';
				printf("%s", line);
				i = 0;
				continue;
			}
			else
			{
				line[i+1] = '\0';
				if (line[i] == ' ' || line[i] == '\t')
				{
					while ((line[i] == ' ' || line[i] == '\t') && i > 0)
						--i;
				}
				else if (line[i] != ' ' && line[i] != '\t')
				{
					while ((line[i] != ' ' && line[i] != '\t') && i > 0)
						--i;
				}
				if (i == 0)
				{
					line[lineLimit] = '\n';
					line[lineLimit+1] = '\0';
					printf("%s", line);
					continue;
				}
				for (j = i +1, k = 0; line[j] != '\0'; ++j, ++k)
					tempLine[k] = line[j];
				line[i+1] = '\n';
				line[i+2] = '\0';
				printf("%s", line);
				copy(line, tempLine);
				i = k;
				continue;
			}
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

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
