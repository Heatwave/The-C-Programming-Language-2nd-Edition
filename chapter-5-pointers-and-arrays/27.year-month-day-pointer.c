#include <stdio.h>

char a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char b[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[2] = {a, b};
/*
static char *daytab[2] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
*/

char *name[] = {"Jan", "Feb"};
char n0[][10] = { {"Jan"}, {"Feb"} };
char n1[][10] = { "Jan", "Feb" };
//char *n2[] = { {"Jan"}, {"Feb"} };

int main()
{
	int day_of_year(int, int, int);
	void month_day(int, int, int*, int*);

	int day = day_of_year(2018, 8, 19);
	printf("%d\n", day);

	day = day_of_year(2018, 13, 19);
	printf("%d\n", day);

	day = day_of_year(2018, 12, 39);
	printf("%d\n", day);

	day = day_of_year(2018, 12, 0);
	printf("%d\n", day);

	int month;
	month_day(2018, 231, &month, &day);
	printf("%d, %d\n", month, day);

	month_day(2018, -1, &month, &day);
	printf("%d, %d\n", month, day);

	month_day(2018, 1234, &month, &day);
	printf("%d, %d\n", month, day);

	month_day(2018, 365, &month, &day);
	printf("%d, %d\n", month, day);

	month_day(2018, 366, &month, &day);
	printf("%d, %d\n", month, day);

	month_day(2016, 366, &month, &day);
	printf("%d, %d\n", month, day);

	return 0;
}

int day_of_year(int year, int month, int day)
{
	int i, leap;
	if (month < 1 || month > 12) {
		printf("error: invalid month: %d\n", month);
		return -1;
	}

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if (day < 1 || day > daytab[leap][month]) {
		printf("error: invalid day: %d\n", day);
		return -1;
	}

	char *p = daytab[leap] + 1;

	for (i = 1; i < month; i++)
		day += *p++;
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (yearday < 1) {
		printf("error: invalid yearday: %d\n", yearday);
		return;
	} else if (leap == 1 && yearday > 366) {
		printf("error: invalid yearday: %d\n", yearday);
		return;
	} else if (leap == 0 && yearday > 365) {
		printf("error: invalid yearday: %d\n", yearday);
		return;
	}

	char *p = daytab[leap] + 1;

	for (i = 1; yearday > *p; i++)
		yearday -= *p++;
	*pmonth = i;
	*pday = yearday;
}

