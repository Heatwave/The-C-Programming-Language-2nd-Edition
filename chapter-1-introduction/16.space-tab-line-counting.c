#include <stdio.h>

main()
{
	int c;
	int space, tab, nl;

	space = tab = nl = 0;

	while((c = getchar()) != EOF) {	
		if (c == ' ') {
			space++;
		} else if (c == '\t') {
			tab++;
		} else if (c == '\n') {
			nl++;
		}
	}
	printf("space: %d\ntab: %d\nnew line: %d\n", space, tab, nl);
}
