#include <stdio.h>

main()
{
	int c, pre;

	while ((c = getchar()) != EOF) {
		if (c != ' ' || pre != ' ') {
			putchar(c);
		}
		pre = c;
	}
}
