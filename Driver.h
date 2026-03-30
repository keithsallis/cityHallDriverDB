#pragma once
#include <iostream>
#include "Date.h"
#include "miniVector.h"
#include "Ticket.h"
#include "Address.h"

// enums for experience level and work status
enum class experienceLevel { Beginner, Intermediate, Advanced };
enum class workStatus { GovernmentEmployee, SelfEmployed, Student, BusinessOwnder, PrivateSector};

using namespace std;

class Driver
{
	// data members
private:
	int age;
	string name;
	string workCity;
	Date dateofBirth;
	miniVector<Ticket> tickets;
	miniVector<Address> frequentLocations;
	Date licenseIssueDate;
	experienceLevel experience;
	workStatus status;

public:
	// constructors
	Driver();
	Driver(int age, string n, string w, Date d, Date l, experienceLevel e, workStatus s);

	// setters
	void setAge(int a);
	void setName(string n);
	void setWorkCity(string w);
	void setDateOfBirth(Date d);
	void setLicenseIssueDate(Date l);
	void setExperience(experienceLevel e);
	void setWorkStatus(workStatus s);

	// getters
	int getAge() const;
	string getName() const;
	string getWorkCity() const;
	Date getDateOfBirth() const;
	Date getLicenseIssueDate() const;
	experienceLevel getExperience() const;
	workStatus getWorkStatus() const;

	// other member functions
	void addTicket(Ticket t);
	void addLocation(Address a);
	
	// printers
	void printTickets() const;
	void printLocations() const;
};

class YouthDriver : public Driver {
private:
	bool licenseExpired;

public:
	YouthDriver();
	YouthDriver(int age, string name, string workCity, Date dob, Date license, bool expired);

	bool isExpired() const;
};

class MiddleAgedDriver : public Driver {
public:
	MiddleAgedDriver();
	MiddleAgedDriver(int age, string name, string workCity, Date dob, Date license);

	void operations();   // Placeholder for future behavior
};

class SeniorDriver : public Driver {
private:
	int yearsWithoutTicket;

public:
	SeniorDriver();
	SeniorDriver(int age, string name, string workCity, Date dob, Date license, int years);

	bool discountEligible() const;
	void operations();
};

class UnfitDriver : public Driver {
private:
	string medicalCondition;
	string accommodation;

public:
	UnfitDriver();
	UnfitDriver(int age, string name, string workCity, Date dob, Date license,
		string condition, string accommodation);

	string getCondition() const;
};

