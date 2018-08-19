#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXLINES 50000

#define ARR_SIZE 1000000

char strstore[ARR_SIZE];

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		//writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}

	return 0;
}

#define MAXLEN 1000

int mygetline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
	clock_t start, finish;
	start = clock();

	int len, nlines;
	int offset = 0;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = &strstore[offset]) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			offset += len;
			lineptr[nlines++] = p;
		}

	finish = clock();
	printf("without alloc: %f\n", ((double)(finish - start)) / CLOCKS_PER_SEC);
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

int mygetline(char *s, int lim)
{
	int c;
	char *t = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*t++ = c;

	if (c == '\n')
		*t++ = c;

	*t = '\0';
	return t - s;
}

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

