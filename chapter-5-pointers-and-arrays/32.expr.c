#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char [], int, char **);
void push(double);
double pop(void);

main(int argc, char **argv)
{
	int type;
	double op2;
	char s[MAXOP];

	if (argc == 1) {
		printf("Usage: expr 1 1 +\n");
		return 1;
	}

	while ((type = getop(s, --argc, ++argv)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}

	printf("Result: %g\n", pop());

	return 0;
}


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

int getop(char *s, int argc, char **argv)
{
	if (argc == 0)
		return EOF;

	char *param = *argv;

	int c;

	while ((*s = c = *param++) == ' ' || c == '\t')
		;

	*++s = '\0';

	if (!isdigit(c) && c != '.')
		return c;

	if (isdigit(c))
		while (isdigit(*s++ = c = *param++))
			;


	if (c == '.')
		while (isdigit(*s++ = c = *param++))
			;

	*s = '\0';

	return NUMBER;
}

