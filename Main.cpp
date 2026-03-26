#include <iostream>
#include "Driver.h"

using namespace std;


int main()
{
	cout << "Adding a driver and testing the functionality of the Driver class" << endl;
	Driver d1(17, "John Doe", "New York", Date(1990, 5, 15), Date(2010, 6, 20), experienceLevel::Advanced, workStatus::PrivateSector);
	// test to make sure i can add tickets and locations to the driver
	// adding some tickets to the driver and some frequent locations

	d1.addTicket(Ticket("New York County", Date(2022, 3, 10)));
	d1.addTicket(Ticket("Kings County", Date(2023, 7, 5)));
	d1.addTicket(Ticket("Queens County", Date(2024, 1, 20)));

	d1.addFrequentLocation(Address("New York", "5th Avenue", 123, 10001));
	d1.addFrequentLocation(Address("New York", "Madison Avenue", 456, 10022));

	// print out some of the driver's information to verify everything is working
	cout << "Driver Name: " << d1.getName() << endl;
	cout << "Work City: " << d1.getWorkCity() << endl;
	cout << "Date of Birth: " << d1.getDateOfBirth().getDay() << "/" << d1.getDateOfBirth().getMonth() << "/" << d1.getDateOfBirth().getYear() << endl;
	cout << "License Issue Date: " << d1.getLicenseIssueDate().getDay() << "/" << d1.getLicenseIssueDate().getMonth() << "/" << d1.getLicenseIssueDate().getYear() << endl;
	cout << "Experience Level: " << (d1.getExperience() == experienceLevel::Beginner ? "Beginner" : (d1.getExperience() == experienceLevel::Intermediate ? "Intermediate" : "Advanced")) << endl;
	cout << "Work Status: " << (d1.getWorkStatus() == workStatus::GovernmentEmployee ? "Government Employee" : (d1.getWorkStatus() == workStatus::SelfEmployed ? "Self Employed" : (d1.getWorkStatus() == workStatus::Student ? "Student" : (d1.getWorkStatus() == workStatus::BusinessOwnder ? "Business Owner" : "Private Sector")))) << endl;

	// print out the ticket information
	cout << "Tickets: " << endl;
	d1.printTickets();

	cout << "Frequent Locations: " << endl;
	d1.printFrequentLocations();

	return 0;
	// to do:
	// 1. implement hashtable to store drivers and information 
	// 2. implement menu system to interact w hastable database
	// 3. implement file I/O to save and load driver information from a file
	// 4. create spreadsheet for file reading
}