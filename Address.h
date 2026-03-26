#pragma once
#include <iostream>

using namespace std;

class Address
{
private:
	string city;
	string street;
	int Number;
	int zipCode;

public:
	// constructors
	Address();
	Address(string c, string s, int n, int z);

	// setters
	void setCity(string c);
	void setStreet(string s);
	void setNumber(int n);
	void setZipCode(int z);

	// getters
	string getCity() const;
	string getStreet() const;
	int getNumber() const;
	int getZipCode() const;
}; 