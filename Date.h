#pragma once
#include <iostream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public :

	// constructors
	Date();
	Date(int d, int m, int y);

	// setters
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	// getters
	int getDay();
	int getMonth();
	int getYear();

};