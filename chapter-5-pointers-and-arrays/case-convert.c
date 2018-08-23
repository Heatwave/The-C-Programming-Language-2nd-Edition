#include <ctype.h>

void strtolower(const char *src, char *dst)
{
	while (*src) {
		*dst++ = tolower(*src++);
	}
	*dst = '\0';
}

