#include <stdio.h>

unsigned getbits(unsigned, int, int);

main()
{
	unsigned a = getbits(255, 3, 4);
	printf("%d\n", a);

	unsigned b = getbits(3, 1, 2);
	printf("%d\n", b);
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
