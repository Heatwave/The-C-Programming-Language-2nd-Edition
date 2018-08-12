#include <stdio.h>

#define swap(t, x, y) { t temp = x; x = y; y = temp; }

int main()
{
	int x, y;
	x = 1;
	y = 2;
	swap(int, x, y);
	printf("%d, %d\n", x, y);

	double a, b;
	a = 1.2;
	b = -3.9;
	swap(double, a, b);
	printf("%g, %g\n", a, b);

	return 0;
}
