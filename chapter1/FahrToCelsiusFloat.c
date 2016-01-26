#include <stdio.h>

/* when fahr = 0, 20, ..., 300 print
 * a table for celsius to fahr 
 * float edition */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/*	temperature lower limit */
	upper = 300;	/* temperature upper limit */
	step = 20;

	fahr = lower;

	printf("A table for Fahrenheit to Celsius:\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
