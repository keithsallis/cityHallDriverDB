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

Driver::Driver(string n, string w, Date dob)
{
    name = n;
    workCity = w;
    dateofBirth = dob;

    age = 0;
    licenseIssueDate = Date();
    experience = experienceLevel::Beginner;
    status = workStatus::GovernmentEmployee;

    tickets = miniVector<Ticket>();
    frequentLocations = miniVector<Address>();
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

void Driver::addLocation(Address a)
{
	frequentLocations.add(a);
}

// printers
void Driver::printTickets() const
{
	for (size_t i = 0; i < tickets.getSize(); ++i)
	{
		Ticket t = tickets.get(i);
		cout << "County: " << t.getCounty() << ", Date Issued: "
			<< t.getDateIssued().getDay() << "/"
			<< t.getDateIssued().getMonth() << "/"
			<< t.getDateIssued().getYear() << endl;
	}
}

void Driver::printLocations() const
{
	for (size_t i = 0; i < frequentLocations.getSize(); ++i)
	{
		Address a = frequentLocations.get(i);
		cout << "City: " << a.getCity() << ", Street: " << a.getStreet()
			<< ", Number: " << a.getNumber() << ", Zip Code: " << a.getZipCode() << endl;
	}
}

// YouthDriver class implementation
YouthDriver::YouthDriver() : licenseExpired(false) {}

YouthDriver::YouthDriver(int age, string name, string workCity, Date dob, Date license, bool expired)
	: Driver(age, name, workCity, dob, license, experienceLevel::Beginner, workStatus::Student),
	licenseExpired(expired)
{
}
bool YouthDriver::isExpired() const {
	return licenseExpired;
}

// MiddleAgedDriver class implementation
MiddleAgedDriver::MiddleAgedDriver() {}

MiddleAgedDriver::MiddleAgedDriver(int age, string name, string workCity, Date dob, Date license)
	: Driver(age, name, workCity, dob, license, experienceLevel::Intermediate, workStatus::PrivateSector)
{
}

void MiddleAgedDriver::operations() {
}
// SeniorDriver class implementation
SeniorDriver::SeniorDriver()
	: Driver(), yearsWithoutTicket(0) {
}

SeniorDriver::SeniorDriver(int age, string name, string workCity, Date dob, Date license, int years)
	: Driver(age, name, workCity, dob, license, experienceLevel::Advanced, workStatus::GovernmentEmployee),
	yearsWithoutTicket(years){}

bool SeniorDriver::discountEligible() const 
{
	return yearsWithoutTicket >= 5;   // Example rule
}

void SeniorDriver::operations() {}
// UnfitDriver class implementation
UnfitDriver::UnfitDriver() {}

UnfitDriver::UnfitDriver(int age, string name, string workCity, Date dob, Date license,
	string condition, string accommodation)
	: Driver(age, name, workCity, dob, license, experienceLevel::Intermediate, workStatus::PrivateSector),
	medicalCondition(condition),
	accommodation(accommodation){}

string UnfitDriver::getCondition() const 
{
	return medicalCondition;
}