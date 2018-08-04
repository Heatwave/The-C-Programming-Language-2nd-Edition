#include <ctype.h>
#include <stdio.h>

main()
{
	printf("%d\n", atoi("123"));
	printf("%d\n", atoi("+1"));
	printf("%d\n", atoi("-0"));
	printf("%d\n", atoi("-123"));
	printf("%d\n", atoi("asd345"));
	printf("%d\n", atoi("789asd345"));
}

int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	
	return sign * n;
}

