#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getch(void);
void ungetch(int);

// compile with getch.c
int main()
{
	int n;
	double array[SIZE], getfloat(double *);
	
	for (n = 0; n < SIZE; n++)
		array[n] = 0.0;

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;

	for (n = 0; n < SIZE; n++)
		printf("%g ", array[n]);

	printf("\n");
	return 0;
}

double getfloat(double *pn)
{
	int c, sign;
	double power;

	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0.0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c) && c != '.') {
			ungetch(sign == 1 ? '+' : '-');
			return 0.0;
		}
	}
	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');

	if (c == '.') {
		c = getch();
	}
	
	for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}

	int eSign = 1;
	if (c == 'e' || c == 'E') {
		c = getch();
		if (c == '-') {
			eSign = -1;
			c = getch();
		} else if (c == '+') {
			c = getch();
		}
	}

	double ePower = 1.0;
	int eCount = 0;
	for (eCount = 0; isdigit(c); c = getch()) 
		eCount = 10.0 * eCount + (c - '0');

	while (eCount-- > 0)
		ePower *= 10;

	*pn = *pn / power * sign;

	if (eSign > 0)
		*pn *= ePower;
	else
		*pn /= ePower;

	if (c != EOF)
		ungetch(c);
	return c;
}
