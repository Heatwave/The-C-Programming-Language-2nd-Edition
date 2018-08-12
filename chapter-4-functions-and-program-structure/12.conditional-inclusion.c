#include <stdio.h>

#define SYSTEM 1

#define BSD 0
#define SYSV 1
#define MSDOC 2

#ifndef HDR
	#if SYSTEM == BSD
		#define HDR "bsd.h"
	#elif SYSTEM == SYSV
		#define HDR "sysv.h"
	#elif SYSTEM == MSDOC
		#define HDR "msdos.h"
	#else
		#define HDR "default.h"
	#endif

	#include HDR
#endif

int main()
{
	printf("%s\n", OS);
}

