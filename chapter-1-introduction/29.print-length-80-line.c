#include <stdio.h>

#define MAXLINE 1000
#define PRINT_LENGTH 80

int myGetline(char line[], int maxline);
char

main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = myGetline(line, MAXLINE)) > 0)
		if (len > PRINT_LENGTH) {
			printf("%s", line);
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
