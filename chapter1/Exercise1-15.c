#include <stdio.h>

/* Exercise 1-15
 * Rewrite the temperture conversion program of Section 1.2 to
 * use a function for conversion. */

#define LOWER	0
#define UPPER	300
#define STEP	20

float FahrToCelsius(int fahr);

main()
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, FahrToCelsius(fahr));
}

float FahrToCelsius(int fahr)
{
	float Celsius;
	Celsius = (5.0/9.0) * (fahr - 32);
	return Celsius;
}
