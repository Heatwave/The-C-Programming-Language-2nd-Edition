#include <stdio.h>
#include <string.h>

#define MAXLEN 10000

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void swap(void *v[], int, int);

void qsort(void *lineptr[], int left, int right,
			int reverse, int foldcase, int (*comp)(void *, void *));

// because qsort is unstable, to test -d
void bubblesort(void *lineptr[], int len, int (*comp)(void*, void*));

int numcmp(const char *, const char *);
int dircmp(const char *, const char *);

void strtolower(const char *src, char *dst);

// gcc 41.sort-with-d.c numcmp.c readlines-writelines.c 6.alloc.c case-convert.c
main(int argc, char *argv[])
{
	char c;
	int nlines;
	int numeric = 0;
	int reverse = 0;
	int foldcase = 0;
	int directory = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch(c) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case 'f':
				foldcase = 1;
				break;
			case 'd':
				directory = 1;
				break;
			default:
				printf("find illegal option %c\n", c);
				return 1;
			}
	
	if (argc != 0) {
		printf("Usage: sort -n -r\n");
		return 1;
	}

	if (numeric && directory) {
		printf("Cannot use the -n and -d at the same\n");
		return 1;
	}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		int (*comp)(void*, void*) = (int (*)(void*, void*))(numeric ? numcmp : strcmp);
		if (directory)
			comp = (int (*)(void*, void*))dircmp;

		if (directory)
			bubblesort((void **) lineptr, nlines, comp);
		else
			qsort((void **) lineptr, 0, nlines-1, reverse, foldcase, comp);

		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void qsort(void *v[], int left, int right,
			int reverse, int foldcase, int (*comp)(void *, void *))
{
	int i, last;
	char s1[MAXLEN], s2[MAXLEN];

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++) {
		char *vi;
		char *vleft;

		if (foldcase) {
			strtolower(v[i], s1);
			vi = s1;
			strtolower(v[left], s2);
			vleft = s2;
		} else {
			vi = v[i];
			vleft = v[left];
		}

		if (reverse && ((*comp)(vi, vleft) > 0))
			swap(v, ++last, i);
		else if (!reverse && ((*comp)(vi, vleft) < 0))
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last-1, reverse, foldcase, comp);
	qsort(v, last+1, right, reverse, foldcase, comp);
}

void bubblesort(void *v[], int len, int (*comp)(void*, void*))
{
	int i, j;
	
	for (i = 0; i < len; i++)
		for (j = 0; j < len; j++) {
			if ((*comp)(v[i], v[j]) < 0)
				swap(v, i, j);
		}
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int dircmp(const char *p1, const char *p2)
{
	char isdircase(const char c);

	const unsigned char *s1 = (const unsigned char *) p1;
	const unsigned char *s2 = (const unsigned char *) p2;
	unsigned char c1, c2;

	do {
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;

		// only compare letters, numbers, blanks
		if (!isdircase(c1) || !isdircase(c2))
			c2 = c1;
			
		if (c1 == '\0')
			return c1 - c2;
	} while (c1 == c2);

	return c1 - c2;
}

char isdircase(const char c)
{
	return isalnum(c) || c == ' ';
}

