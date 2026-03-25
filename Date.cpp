#include "Date.h"

// constructors
Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

// setters
void Date::setDay(int d)
{
	day = d;
}

void Date::setMonth(int m)
{
	month = m;
}

void Date::setYear(int y)
{
	year = y;
}

// getters
int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}