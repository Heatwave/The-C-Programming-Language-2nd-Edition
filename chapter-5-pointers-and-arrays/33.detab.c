#include <stdio.h>

main(int argc, char *argv[])
{
	int c, n, i;
	int cur;

	if (argc == 1)
		n = 8;
	else if (argc == 2)
		n = atoi(*++argv);
	else {
		printf("Usage: detab (8)(tab stop)\n");
		return 1;
	}

	cur = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (i = n - cur; i > 0; --i)
				putchar(' ');

			cur = 0;
		} else {
			putchar(c);
			++cur;
			if (cur >= n || c == '\n')
				cur = 0;
		}
	}
}

