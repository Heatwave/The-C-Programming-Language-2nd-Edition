#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LEN 1024

void itoa(int n, char s[], int minWidth);
void reverse(char[]);


main()
{
	int a = 0;
	char s[MAX_LEN];
	itoa(a, s, 5);
	printf("a: %d, %s\n", a, s);

	a = INT_MIN;
	itoa(a, s, 20);
	printf("INT_MIN: %d, %s\n", a, s);

	a = INT_MAX;
	itoa(a, s, 15);
	printf("INT_MAX: %d, %s\n", a, s);

	a = 1234567890;
	itoa(a, s, 5);
	printf("a: %d, %s\n", a, s);
}

void itoa(int n, char s[], int minWidth)
{
	int i;
	int sign = n;

	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while (n /= 10);

	if (sign < 0)
		s[i++] = '-';

	int needSpace = minWidth - strlen(s);
	while (needSpace-- > 0) {
		s[i++] = ' ';
	}

	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

