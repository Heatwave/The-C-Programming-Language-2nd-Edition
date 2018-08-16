#include <stdio.h>

int main()
{
	void strcpyArray(char*, char*);

	char t[] = "Hello, World!";
	char s[100];
	strcpyArray(s, t);
	printf("%s\n", s);

	return 0;
}

void strcpyArray(char *s, char *t)
{
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

