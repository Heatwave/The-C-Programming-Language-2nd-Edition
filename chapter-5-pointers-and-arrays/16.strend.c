#include <stdio.h>

int main()
{
	int strend(char*, char*);

	char *s = "qweasdzxc123Hello";
	char *t = "Hello";
	int end = strend(s, t);
	printf("%d\n", end);

	return 0;
}

int strend(char *s, char *t)
{
	char *sStart = s;
	char *tStart = t;

	while (*s)
		s++;

	while (*t)
		t++;

	while ((*s-- == *t--) && (t != tStart) & (s != sStart))
		;

	if (t == tStart)
		return 1;
	else
		return 0;
}

