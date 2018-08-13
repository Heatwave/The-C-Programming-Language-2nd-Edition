#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getch(void);
void ungetch(int);

// compile with getch.c
int main()
{
	int n, array[SIZE], getint(int *);

	for (n = 0; n < SIZE; n++)
		array[n] = 0;
	
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	
	for (n = 0; n < SIZE; n++)
		printf("%d ", array[n]);

	printf("\n");
	return 0;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) {
			ungetch(sign == 1 ? '+' : '-');
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
