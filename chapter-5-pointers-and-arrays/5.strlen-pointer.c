#include <stdio.h>

int main()
{
	int strlen(char*);

	char array[100];
	char *ptr = "Hello";

	int l = strlen("hello, world");
	printf("%d\n", l);

	l = strlen(array);
	printf("%d\n", l);

	l = strlen(ptr);
	printf("%d\n", l);
}

int strlen(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;

	return n;
}
