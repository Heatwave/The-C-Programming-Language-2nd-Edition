#include <stdio.h>

int main()
{
	void mystrcat(char*, char*);

	char s[100] = "Hello";
	char *t = ", World!";
	mystrcat(s, t);
	printf("%s\n", s);

	return 0;
}

void mystrcat(char *s, char *t)
{
	while (*s)
		s++;

	while ((*s++ = *t++))
		;
}

