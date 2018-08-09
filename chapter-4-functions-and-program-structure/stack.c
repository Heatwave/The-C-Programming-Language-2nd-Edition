#include <stdio.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void top(void)
{
	if (sp > 0)
		printf("stack top: %g\n", val[sp-1]);
	else
		printf("stack empty\n");
}

void duplicate(void)
{
	if (sp > MAXVAL -1)
		printf("error: stack full, can't duplicate\n");
	else {
		double element = pop();
		push(element);
		push(element);
	}
}

void swap(void)
{
	if (sp < 2)
		printf("error: stack size < 2, can't swap\n");
	else {
		double e1 = pop();
		double e2 = pop();
		push(e1);
		push(e2);
	}
}

void empty(void)
{
	sp = 0;
}
