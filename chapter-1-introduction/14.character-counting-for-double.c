#include <stdio.h>

/* count characters in input; 2nd version */
main()
{
	double nc;

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
}
