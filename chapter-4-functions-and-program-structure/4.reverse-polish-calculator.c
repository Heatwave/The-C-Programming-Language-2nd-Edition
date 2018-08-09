#include <stdio.h>
#include <string.h>
#include <stdlib.h>	// for atof()
#include <math.h>	// for fmod()
#include "calc.h"

#define MAXOP 100	// max size of operand or operator
#define MAX_VAR_LEN 26	// max size of array for variables

void mathfunc(char[]);
void setVar(double, double);
void getVar(char[]);

double variables[MAX_VAR_LEN];
int variableFlags[MAX_VAR_LEN];	// if [0] is 0, means 'a' not set, if [0] is 1, means 'a' set

// compile with stack.c, getop.c, getch.c
main()
{
	int type;
	double op2;
	char s[MAXOP];

	int i;

	for (i = 0; i < MAX_VAR_LEN; i++)
		variableFlags[i] = 0;

	while ((type = getop(s)) != EOF) {
		switch(type) {
		case NUMBER:
			push(atof(s));
			break;
		case VAR:
			getVar(s);
			break;
		case FUNC:
			mathfunc(s);
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
		case '%':
			op2 = pop();
			if (op2 == 0.0)
				printf("error: can not mod 0\n");
			else
				push(fmod(pop(), op2));
			break;
		case '=':
			op2 = pop();
			setVar(pop(), op2);
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

void mathfunc(char s[])
{
	int index;
	if (0 == strrindex(s, "sin")) {
		push(sin(pop()));
		return;
	}

	if (0 == strrindex(s, "exp")) {
		push(exp(pop()));
		return;
	}

	if (0 == strrindex(s, "pow")) {
		double ey = pop();
		push(pow(pop(), ey));
		return;
	}

	printf("error: unknown func %s\n", s);
	return;
}

void setVar(double varIndex, double value)
{
	int index = (int)varIndex;	
	if (index < 0 || index > MAX_VAR_LEN) {
		printf("error: cannot set variable, invalid variable: %c\n", index + 'a');
		return;
	}
	
	variables[index] = value;
	variableFlags[index] = 1;

	push(value);	// to show result

	return;
}

void getVar(char s[])
{
	if (strlen(s) != 1 && s[0] != 0) {
		// if variable is 'a', s[0] == 0, strlen(s) == 0
		printf("error: cannot get variable, invalid variable: %s\n", s);
		return;
	}

	double value = atof(s);
	int index = (int)value;
	if (variableFlags[index] == 0)
		push(value);
	else
		push(variables[index]);

	return;
}
