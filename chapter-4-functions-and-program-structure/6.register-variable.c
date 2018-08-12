#include <stdio.h>
#include <time.h>

#define LOOP_COUNT 1e8

void withRegister(void);
void withoutRegister(void);

int main()
{
	clock_t start, finish;
	start = clock();
	withRegister();
	finish = clock();
	printf("withRegister duration: %f\n", ((double)(finish - start)) / CLOCKS_PER_SEC);

	start = clock();
	withoutRegister();
	finish = clock();
	printf("withoutRegister duration: %f\n", ((double)(finish - start)) / CLOCKS_PER_SEC);
}

void withRegister(void)
{
	register int i;
	for (i = 0; i < LOOP_COUNT; i++)
		;

}

void withoutRegister(void)
{
	int i;
	for (i = 0; i < LOOP_COUNT; i++)
		;
}
