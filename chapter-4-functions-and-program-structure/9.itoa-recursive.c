#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[]);

int main()
{
	char s[1024];
	int n = INT_MAX;
	itoa(n, s);
	printf("s: %s, n: %d\n", s, n);

	n = -2147483647;
	itoa(n, s);
	printf("s: %s, n: %d\n", s, n);

	n = -INT_MAX;
	itoa(n, s);
	printf("s: %s, n: %d\n", s, n);

	n = -0;
	itoa(n, s);
	printf("s: %s, n: %d\n", s, n);

	n = 0;
	itoa(n, s);
	printf("s: %s, n: %d\n", s, n);

	return 0;
}

void itoa(int n, char s[])
{
	if (n < 0) {
		s[0] = '-';
		n = -n;
	}
	if (n / 10)
		itoa(n / 10, s);
	
	int digits = 0;
	int t = n;
	while (t = t / 10)
		digits++;
	if (s[0] == '-')
		digits++;

	s[digits++] = n % 10 + '0';
	s[digits] = '\0';
}

