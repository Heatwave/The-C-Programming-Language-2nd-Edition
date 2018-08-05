#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char[]);


main()
{
	int a = 0;
	char s[10];
	itoa(a, s);
	printf("%s\n", s);

	a = INT_MIN;
	itoa(a, s);
	printf("%s\n", s);

	a = INT_MAX;
	itoa(a, s);
	printf("%s\n", s);
}

void itoa(int n, char s[])
{
	int i, sign;
	int preN = n;
	int nIsMinNagetive = n != 0 && n == -n;

	if ((sign = n) < 0) {
		if (nIsMinNagetive) {
			n += 1;
			n = -n;
		} else {
			n = -n;
		}
	}

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);

	if (nIsMinNagetive)
		s[strlen(s) - 1] += 1;
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
