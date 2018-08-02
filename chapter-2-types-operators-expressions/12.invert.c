#include <stdio.h>

int invert(int, int, int);

main()
{
	int a = invert(255, 0, 4);
	printf("%d\n", a);

	int b = invert(0, 4, 4);
	printf("%d\n", b);
	
	int c = invert(15, 4, 4);
	printf("%d\n", c);
}

int invert(int x, int p, int n)
{
	return x ^ (~(~0 << n) << p);
}

