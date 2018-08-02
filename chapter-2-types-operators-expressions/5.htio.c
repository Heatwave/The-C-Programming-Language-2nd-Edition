#include <stdio.h>

int htoi(char[]);

main()
{
	int n = htoi("0x123abc");
	printf("%d\n", n);
	n = htoi("0X123abc");
	printf("%d\n", n);
	n = htoi("123abc");
	printf("%d\n", n);
	n = htoi("FF");
	printf("%d\n", n);
	n = htoi("1F");
	printf("%d\n", n);
	n = htoi("D");
	printf("%d\n", n);
	n = htoi("3");
	printf("%d\n", n);
	n = htoi("3FQWE");
	printf("%d\n", n);
}

int htoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; ; ++i) {
		if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
			i++;
			continue;
		}
		
		if (s[i] >= '0' && s[i] <= '9') {
			n = 16 * n + (s[i] - '0');
		} else if (s[i] >= 'a' && s[i] <= 'f') {
			n = 16 * n + (s[i] - 'a' + 10);
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			n = 16 * n + (s[i] - 'A' + 10);
		} else {
			break;
		}
	}
	return n;
}
