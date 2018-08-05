#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int mygetline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

main()
{
	char line[MAXLINE];
	int found = 0;
	int p;

	while (mygetline(line, MAXLINE) > 0) {
		p = strrindex(line, pattern);
		if (p >= 0) {
			printf("%s", line);
			found++;
		}
	}
	return found;
}

int mygetline(char s[], int lim)
{
	int c, i;
	i =0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strrindex(char s[], char t[])
{
	int i, j, k;

	for (i = strlen(s) - 2; i > 0; i--) {
		for (j = i, k = strlen(t) - 1; j > 0 && k > 0 && s[j] == t[k]; j--, k--)
			;

		if (k == 0)
			return j;
	}
	return -1;
}
