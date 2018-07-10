#include <stdio.h>

#define MAXLINE 1000

int myGetline(char line[], int maxline);
char

main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	int i;

	max = 0;
	while ((len = myGetline(line, MAXLINE)) > 0) {
		for (i = len; i >= 0; --i) {
			if (line[i] == ' ' || line[i] == '\t')
				line[i] = '\0';
			else if	(line[i] == '\n' || line[i] == '\0')
				continue;
			else
				break;
		}
		
		if (line[0] != '\0' && line[0] != '\n') {
			printf("%s", line);
		}
	}
	
	return 0;
}

int myGetline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
