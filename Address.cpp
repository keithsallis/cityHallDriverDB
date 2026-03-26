#include "Address.h"

// constructors
Address::Address()
{
	city = "";
	street = "";
	Number = 0;
	zipCode = 0;
}

Address::Address(string c, string s, int n, int z)
{
	city = c;
	street = s;
	Number = n;
	zipCode = z;
}

// setters, for changing after creation
void Address::setCity(string c)
{
	city = c;
}

void Address::setStreet(string s)
{
	street = s;
}

void Address::setNumber(int n)
{
	Number = n;
}

void Address::setZipCode(int z)
{
	zipCode = z;
}

// getters, for accessing data members
string Address::getCity() const
{
	return city;
}

string Address::getStreet() const
{
	return street;
}

int Address::getNumber() const
{
	return Number;
}

int Address::getZipCode() const
{
	return zipCode;
}
