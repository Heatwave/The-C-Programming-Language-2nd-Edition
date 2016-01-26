#include <stdio.h>

/* when fahr = 0, 20, ..., 300 print
 * a table for celsius to fahr */
main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;	/*	temperature lower limit */
	upper = 300;	/* temperature upper limit */
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr-32) / 9;
		printf("%3d\t%4d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
