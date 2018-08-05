#include <stdio.h>

#define MAX_LEN 1024

void expand(char s1[], char s2[]);

main()
{
	char s1[] = "-a-z-A-Z-0-9-asd-5-5-5-9a-ZZ-A-G-N-T-Z";
	char s2[MAX_LEN];
	expand(s1, s2);
	printf("%s\n", s2);

	char s[] = "-a-z 0-9 a-d-f -0-2 some text 1-1 WITH CAPITALS! 0-0 5-3 -";
	char t[MAX_LEN];
	expand(s, t);
	printf("%s\n", t);
}

void expand(char s1[], char s2[])
{
	int i, j, k;

	for (i = 0, j = 0; s1[i] != '\0'; i++) {
		if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {
			int p = s1[i-1];
			int n = s1[i+1];
			if (p < n && 
				((p >= 'a' && n <= 'z') || (p >= 'A' && n <= 'Z') || (p >= '0' && n <= '9'))
			) {
				for (k = p + 1; k < n; k++)
					s2[j++] = k;
			} else {
				s2[j++] = s1[i];
			}
		} else {
			s2[j++] = s1[i];
		}
	}

	s2[j] = '\0';
}
