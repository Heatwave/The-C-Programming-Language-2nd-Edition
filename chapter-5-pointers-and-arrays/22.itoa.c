#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
	void itoa(int, char*);

	int n = 0;
	char s[10];
	itoa(n, s);
	printf("%d to %s\n", n, s);

	n = -0;
	itoa(n, s);
	printf("%d to %s\n", n, s);

	n = 1234;
	itoa(n, s);
	printf("%d to %s\n", n, s);

	n = INT_MIN;
	itoa(n, s);
	printf("%d to %s\n", n, s);

	n = INT_MAX;
	itoa(n, s);
	printf("%d to %s\n", n, s);

	return 0;
}

void itoa(int n, char *s)
{
	void reverse(char*);

	char *p = s;
	int sign = n;

	do {
		*s++ = abs(n % 10) + '0';
	} while (n /= 10);

	if (sign < 0)
		*s++ = '-';


	*s = '\0';
	reverse(p);
}

void reverse(char *s)
{
	char *t = s + strlen(s) - 1;
	char c;

	while (s < t) {
		c = *s;
		*s = *t;
		*t = c;
		s++;
		t--;
	}
}

