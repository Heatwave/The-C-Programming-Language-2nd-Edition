#include <stdio.h>

#define MAXLINE 1024

int myGetline(char line[], int maxline);
int myGetlineV1(char line[], int maxline);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = myGetlineV1(line, MAXLINE)) > 0) {
		printf("%s", line);
	}

	return 0;
}

int myGetline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int myGetlineV1(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1; ++i) {
		if ((c = getchar()) == '\n')
			break;
		if (c == EOF)
			break;

		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
