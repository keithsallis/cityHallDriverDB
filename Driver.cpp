#include "Driver.h"

// constructors
Driver::Driver()
{
	age = 0;
	name = "";
	workCity = "";
	dateofBirth = Date();
	licenseIssueDate = Date();
	experience = experienceLevel::Beginner;
	status = workStatus::GovernmentEmployee;
}

Driver::Driver(int a, string n, string w, Date d, Date l, experienceLevel e, workStatus s)
{
	age = a;
	name = n;
	workCity = w;
	dateofBirth = d;
	tickets = miniVector<Ticket>();
	frequentLocations = miniVector<Address>();
	licenseIssueDate = l;
	experience = e;
	status = s;
}

// setters
void Driver::setAge(int a)
{
	age = a;
}

void Driver::setName(string n)
{
	name = n;
}

void Driver::setWorkCity(string w)
{
	workCity = w;
}

void Driver::setDateOfBirth(Date d)
{
	dateofBirth = d;
}

void Driver::setLicenseIssueDate(Date l)
{
	licenseIssueDate = l;
}


void Driver::setExperience(experienceLevel e)
{
	experience = e;
}

void Driver::setWorkStatus(workStatus s)
{
	status = s;
}

// getters
int Driver::getAge() const
{
	return age;
}

string Driver::getName() const
{
	return name;
}

string Driver::getWorkCity() const
{
	return workCity;
}

Date Driver::getDateOfBirth() const
{
	return dateofBirth;
}

Date Driver::getLicenseIssueDate() const
{
	return licenseIssueDate;
}

experienceLevel Driver::getExperience() const
{
	return experience;
}

workStatus Driver::getWorkStatus() const
{
	return status;
}

// other member functions

void Driver::addTicket(Ticket t)
{
	tickets.add(t);
}

void Driver::addFrequentLocation(Address a)
{
	frequentLocations.add(a);
}

void Driver::printFrequentLocations() const
{
	for (int i = 0; i < frequentLocations.getSize(); i++) {
		Address a = frequentLocations.get(i);
		cout << "  City: " << a.getCity() << ", Street: " << a.getStreet() << ", Number: " << a.getNumber() << ", Zip Code: " << a.getZipCode() << endl;
	}
}

void Driver:: printTickets() const
{
	for (int i = 0; i < tickets.getSize(); i++) {
		Ticket t = tickets.get(i);
		cout << "  County: " << t.getCounty() << ", Date Issued: " << t.getDateIssued().getDay() << "/" << t.getDateIssued().getMonth() << "/" << t.getDateIssued().getYear() << endl;
	}
}
