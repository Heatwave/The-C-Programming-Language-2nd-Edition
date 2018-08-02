#include <stdio.h>

int bitcount(unsigned);

main()
{
	printf("%d\n", bitcount(255));
	printf("%d\n", bitcount(15));
	printf("%d\n", bitcount(1));
	printf("%d\n", bitcount(0));
	printf("%d\n", bitcount(~0U));
}

int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;

	return b;
}
