#include <stdio.h>

int lower(int);

main()
{
	printf("%c\n", lower('S'));
	printf("%c\n", lower('A'));
	printf("%c\n", lower('Z'));
	printf("%c\n", lower('a'));
}

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

