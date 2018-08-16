#include <stdio.h>
#include <ctype.h>

int main()
{
	printf("%d\n", atoi("123"));
	printf("%d\n", atoi("+1"));
	printf("%d\n", atoi("-0"));
	printf("%d\n", atoi("-123"));
	printf("%d\n", atoi("asd345"));
	printf("%d\n", atoi("789asd345"));

	return 0;
}

int atoi(char *s)
{
	int sign, n;

	while (isspace(*s))
		s++;

	sign = (*s == '-') ? -1 : 1;

	if (*s == '+' || *s == '-')
		s++;

	n = 0;
	while (isdigit(*s))
		n = 10 * n + (*s++ - '0');

	return sign * n;
}
