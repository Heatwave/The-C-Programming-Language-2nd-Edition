#include <stdio.h>

int main()
{
	void mystrcpy(char*, char*);

	char t[] = "Hello, World!";
	char s[100];
	mystrcpy(s, t);
	printf("%s\n", s);

	return 0;
}

void mystrcpy(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

