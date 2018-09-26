#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdarg.h>
#include <stdlib.h>

#define PERMS 0666

void error(char *fmt, ...);

main(int argc, char *argv[])
{
	int f1, f2, n;
	char buf[BUFSIZ];

	if (argc != 3)
		error("usage: cp from to");
	if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
		error("cp: can't open %s", argv[1]);
	if ((f2 = open(argv[2], PERMS, 0)) == -1)
		error("cp: can't create %s, mode %03o", argv[2], PERMS);

	while ((n = read(f1, buf, BUFSIZ)) > 0)
		if (write(f2, buf, n) != n)
			error("cp: write error on file %s", argv[2]);
	
	return 0;
}

void error(char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}

