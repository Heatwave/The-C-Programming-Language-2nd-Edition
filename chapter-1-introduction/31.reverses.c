#include <stdio.h>

#define MAXLINE 999

void reverse(char s[]);
int myGetline(char line[], int maxline);

int main()
{
	char line[MAXLINE];

	while(myGetline(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

void reverse(char s[])
{
	int len, i, left;
	char temp;
	len = 0;
	while (s[len] != '\n')
		len++;

	int middle;
	if ((len % 2) == 0)
		middle = len / 2;
	else
		middle = len / 2 + 1;

	for (i = len - 1; i >= middle; --i) {
		left = len - 1 - i;
		temp = s[left];
		s[left] = s[i];
		s[i] = temp;
	}
}

int myGetline(char s[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline -1 && (c = getchar()) != EOF && c!= '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
