#include <stdio.h>
#include <string.h>

int main()
{
	int mystrncmp(char *, char *, int);

	char *s = "Hellp";
	char *t = "Hello";
	int diff = mystrncmp(s, t, 5);
	printf("%d\n", diff);

	diff = strncmp(s, t, 5);
	printf("%d\n", diff);

	return 0;
}

int mystrncmp(char *cs, char *ct, int n)
{
	for (; *cs == *ct && n > 0; cs++, ct++)
		if (*cs == '\0')
			return 0;

	if (n == 0)
		return 0;

	return *cs - *ct;
}

