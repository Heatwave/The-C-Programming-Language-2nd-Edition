#include <stdio.h>

/* when celsius = 0, 20, ..., 300 print
 * a table for fahr to celsius 
 * float edition */

/* Exercise 1-4 */

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/*	temperature lower limit */
	upper = 300;	/* temperature upper limit */
	step = 20;

	celsius = lower;

	printf("A table for Celsius to Fahrenheit:\n");
	while (celsius <= upper) {
		fahr = celsius * 1.8 + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
