#include <stdio.h>

#define MAXLINE 1000

int myGetline(char line[], int maxline);
char

main()
{
	int len;
	int max;
	char line[MAXLINE];

	max = 0;
	while ((len = myGetline(line, MAXLINE)) > 0)
		printf("%d: %s", len, line);
	
	return 0;
}

int myGetline(char s[], int lim)
{
	int c, i;

	i = 0;

	while((c = getchar()) != EOF && c != '\n') {
		if (i < lim - 1)
			s[i++] = c;
		else
			i++;
	}

	if (c == '\n' && i < lim - 1) {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}
