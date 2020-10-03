#include <stdio.h>

/* count characters in input; 1st version */
main()
{
	long int nc; //big integer

	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}
