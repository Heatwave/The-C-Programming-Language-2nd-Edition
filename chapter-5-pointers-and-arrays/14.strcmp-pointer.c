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
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

