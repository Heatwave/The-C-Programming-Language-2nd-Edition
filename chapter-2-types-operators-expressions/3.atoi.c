#include <stdio.h>

int atoi(char[]);
int htoi(char[]);

main()
{
	int a = atoi("1234567890");
	printf("%d\n", a);
	a = atoi("1234abc567890");
	printf("%d\n", a);
	
	//repeat lines 10 and 11 using htoi
	a = htoi("1234abc567890");
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

/*
Function htoi should return hexadecimal form. Current function atoi returns only decimal form
For example, line 10 (originally at line 9) returns a value of 1234 rather than the correct decimal value of 320278871046288.
See function below. In current form, return is an int, can also be a long double to support larger inputs
*/

int htoi(char s[])
{
	int i;
	long double n;

	n = 0;
	for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); ++i)
	{
		if (i == 0 && s[i] == '0')
			i = 2;
		else if (s[i] >= '0' && s[i] <= '9')
			n = 16 * n + (s[i] - '0');
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = 16 * n + (s[i] - 'a' + 10.0);
		else
			n = 16 * n + (s[i] - 'A' + 10.0);
	}
	return n;
}


