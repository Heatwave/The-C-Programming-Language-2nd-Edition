#include <stdio.h> 

main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	celsius = lower;

	printf("Celsius-Fahrenheit table\n");
	while (celsius <= upper) {
		fahr = celsius / (5.0 / 9.0) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		fahr = fahr + step;
		celsius += step;
	}
}
