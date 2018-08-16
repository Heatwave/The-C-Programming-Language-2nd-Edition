#include <stdio.h>

int main()
{
	int mygetline(char *, int);
	char s[100];
	int len = mygetline(s, 100);
	printf("%d %s\n", len, s);

	return 0;
}

int mygetline(char *s, int lim)
{
	int c;
	char *t = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	
	if (c == '\n')
		*s++ = c;
	
	*s = '\0';
	return s - t - 1;
}
