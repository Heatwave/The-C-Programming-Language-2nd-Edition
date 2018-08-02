#include <stdio.h>

void squeeze(char[], char[]);

main()
{
	char s[] = "test";
	char t[] = "te";
	squeeze(s, t);
	printf("%s\n", s);

	char s1[] = "test";
	char t1[] = "st";
	squeeze(s1, t1);
	printf("%s\n", s1);

	char s2[] = "test";
	char t2[] = "sta";
	squeeze(s2, t2);
	printf("%s\n", s2);

	char s3[] = "test";
	char t3[] = "test";
	squeeze(s3, t3);
	printf("%s\n", s3);

	char s4[] = "test";
	char t4[] = "";
	squeeze(s4, t4);
	printf("%s\n", s4);
}

void squeeze(char s[], char t[])
{
	if (t[0] == '\0')
		return;

	int i ,j, k;
	int same;

	for (i = j = 0; s[i] != '\0'; i++) {
		same = 1;

		for (k = 0; t[k] != '\0'; k++) {
			if (s[i+k] == '\0') {
				same = 0;
				break;
			}


			if (t[k] != s[i+k]) {
				same = 0;
				break;
			}
		}

		if (same == 1) {
			i += k - 1;
		} else {
			s[j++] = s[i];
		}
	}

	s[j] = '\0';
}

