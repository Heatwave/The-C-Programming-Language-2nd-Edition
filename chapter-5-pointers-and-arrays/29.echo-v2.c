#include <stdio.h>

main(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
		//printf((argc > 1) ? "%s " : "%s", *++argv);
	printf("\n");

	return 0;
}

