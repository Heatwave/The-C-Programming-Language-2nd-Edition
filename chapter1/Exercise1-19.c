#include <stdio.h>

/* Exercise 1-19
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.*/

#define MAXLINE 1000

int reverse(char *s);

main()
{
	char line[MAXLINE];

	int c, i;

	i = 0;

	while ((c = getchar()) != EOF)
	{
		line[i] = c;
		if (c == '\n')
		{
			line[i+1] = '\0';
			if (reverse(line) == 1)
			{
				printf("%s", line);
				i = 0;
			}
			else
			{
				printf("reverse failed");
				return 0;
			}
		}
		else
			++i;
	}
}

int reverse(char s[])
{
	int length;
	for (length = 0; s[length] != '\n'; length++);
	int left = 0;
	int right = length - 1;
	int temp;
	for (; left < right; ++left, --right)
	{
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
	}
	return 1;
}
