#include <stdio.h>

int main()
{
	int mystrcmp(char*, char*);

	char *s = "Hello";
	char *t = "Hello";
	int diff = mystrcmp(s, t);
	printf("%d\n", diff);

	return 0;
}

int mystrcmp(char *s, char *t)
{
	int i;

	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

