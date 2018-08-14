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
	char *p = s;

	while (*p != '\0')
		p++;
	
	return p - s;
}

