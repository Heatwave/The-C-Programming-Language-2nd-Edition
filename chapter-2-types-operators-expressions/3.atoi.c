#include <stdio.h>

int atoi(char[]);

main()
{
	int a = atoi("1234567890");
	printf("%d\n", a);
	a = atoi("1234abc567890");
	printf("%d\n", a);
}

int atoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
