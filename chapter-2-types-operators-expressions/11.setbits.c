#include <stdio.h>

int setbits(int, int, int, int);

main()
{
	int a = setbits(255, 0, 4, 0);
	printf("%d\n", a);

	int b = setbits(1, 1, 3, 4);
	printf("%d\n", b);

	int c = setbits(218, 2, 4, 9);
	printf("%d\n", c);
}

int setbits(int x, int p, int n, int y)
{
	/* xxx............xxx  x */
	/* yyy...........ynnn  y */

	/* least significant position of the bits touched */
	int r = p - n + 1;

	/* 000...011110...000  mask */
	/*        p  r ...210  position */
	int mask = ~(~0 << p + 1) & (~0 << r);

	/* 000...0nnnn0...000  */
	y = (y << r) & mask;

	/* xxx...x0000x...xxx */
	x = x & ~mask;

	/* xxx...xnnnnx...xxx */
	return x | y;
}

