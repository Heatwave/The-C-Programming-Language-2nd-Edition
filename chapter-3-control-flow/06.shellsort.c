#include <stdio.h>

void shellsort(int [], int);
void printArr(int [], int);

main()
{
	int len = 12;
	int v[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	printArr(v, len);
	shellsort(v, len);
	printArr(v, len);
}

// sort v[0]...v[n-1] into increasing order
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v [j + gap]; j -= gap) {
				printf("gap: %d, i: %d, j: %d, j+gap: %d\n", gap, i, j, j+gap);
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}

void printArr(int v[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", v[i]);
	printf("\n");
}
