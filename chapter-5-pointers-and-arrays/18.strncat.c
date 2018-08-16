#include <stdio.h>
#include <string.h>

int main()
{
	char *mystrncat(char*, char *, int);

	char s[100] = "Hello, ";
	char *ct = "world!";
	char *t = mystrncat(s, ct, 5);
	printf("%s\n", s);
	printf("%s\n", t);

	t = strncat(s, ct, 8);
	printf("%s\n", t);

	return 0;
}

char *mystrncat(char *s, char *ct, int n)
{
	char *ts = s;
	while (*++ts)
		;
	
	for (; n > 0 && ct != '\0'; n--)
		*ts++ = *ct++;

	*ts = '\0';

	return s;
}
