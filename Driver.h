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
	void addFrequentLocation(Address a);
	void printFrequentLocations() const;
	void printTickets() const;
	
};