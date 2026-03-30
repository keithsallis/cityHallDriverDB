#include <iostream>
#include <limits>

#include "Driver.h"
#include "hashtable.h"
#include "DriverSort.h"
#include "loadFile.h"

using namespace std;

// print drivers function to test miniVector sorting
void static printDrivers(const miniVector<Driver>& drivers)
{
	for (size_t i = 0; i < drivers.getSize(); ++i)
	{
		const Driver& d = drivers.get(i);
		cout << "Name: " << d.getName() << "| License Issue Date: "
			 << d.getLicenseIssueDate().getDay() << "/"
			 << d.getLicenseIssueDate().getMonth() << "/"
			 << d.getLicenseIssueDate().getYear() << endl;
	}
}

void static menu()
{
	CHashTable driverDB(50);
	miniVector<Driver> inactiveDriverDB;
	miniVector<Driver> driverList;
	Driver* tempDriver;
	Driver* searchResult;
	Ticket ticket;
	Date date;
	string city = " ", street = " ", county = " ", searchName = " ";
	int streetNumber = 0, zipCode = 0, choice = 0, day = 0, month = 0, year = 0, numReturn = 0;


	cout << "=== Driver Database Menu ===" << endl;
	cout << "All searches are space and case sensitive" << endl;
	cout << "1. Upload driver data from file" << endl;
	cout << "2. Search for driver by name" << endl;
	cout << "3. Add ticket to driver" << endl;
	cout << "4. Add frequent location to driver" << endl;
	cout << "5. Remove and add to inactive drivers DB" << endl;
	cout << "6. search N most recently issued liscenses" << endl;
	cout << "7. search N Oldest issued liscenses" << endl;
	cout << "8. Display inactive drivers" << endl;
	cout << "9. Exit" << endl; 

	cout << "Pick a choice: "; 
	if (!(cin >> choice)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a number.\n";
		choice = 0;
	}

	do
	{
		switch (choice)
		{
			case 1:
				cout << "You chose to upload driver data from file." << endl;
				loadDriversFromCSV("drivers_100_test_data.csv", driverDB, driverList);
				sortByLicense(driverList);

				break;
			case 2:
				cout << "Enter Search Name: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, searchName); // consume leftover newline

				searchResult = driverDB.search(searchName);

				if (searchResult != nullptr)
				{
					cout << "\nSearch Result:\n";
					cout << searchResult->getName() << " | " << searchResult->getWorkCity() << endl;
				}

				break;
			case 3:
				cout << "Enter Search Name to add ticket: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, searchName); // consume leftover newline

				searchResult = driverDB.search(searchName);

				cout << "Enter ticket county: ";
				cin >> county; 

				cout << "Enter ticket date (day month year): ";
				cin >> day;
				cout << "/";
				cin >> month;
				cout << "/";
				cin >> year;

				ticket.setTicketInfo(county, Date(day, month, year));
				
				searchResult->addTicket(ticket);

				cout << "Added ticket to " << searchResult->getName() << "'s record." << endl;

				// display the updated tickets for the driver
				searchResult->printTickets();

				break;
			case 4:
				cout << "Enter Search Name to add location: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, searchName); // consume leftover newline

				searchResult = driverDB.search(searchName);

				cout << "Enter city: ";
				getline(cin, city);
				cout << "Enter street: ";
				getline(cin, street);
				cout << "Enter number: ";
				cin >> streetNumber;
				cout << "Enter zip code: ";
				cin >> zipCode;

				cout << "Added location to " << searchResult->getName() << "'s record." << endl;

				// display the updated frequent locations for the driver
				searchResult->printLocations();
				break;
			case 5:
				cout << "Enter Driver's name to remove:";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, searchName); // consume leftover newline

				// place holder driver while it gets transferred to inactive DB
				tempDriver = driverDB.getDriverRef(searchName);

				// if driver exists, add to inactive DB before removing from active DB
				if (tempDriver != nullptr)
				{
					inactiveDriverDB.add(*tempDriver);
					cout << "Driver '" << tempDriver->getName() << "' added to inactive drivers database." << endl;
				}

				// print names of inactive drivers to verify
				cout << "=== Inactive Drivers ===" << endl;
				for (size_t i = 0; i < inactiveDriverDB.getSize(); ++i)
				{
					cout << inactiveDriverDB.get(i).getName() << endl;
				}

				driverDB.remove(searchName);
				break;
			case 6:
				cout << "Enter amount of liscenses to return: ";
				cin >> numReturn;
				
				printMostRecent(driverList, numReturn);
				break;
			case 7:
				cout << "Enter amount of liscenses to return: ";
				cin >> numReturn;

				printOldest(driverList, numReturn);

				break;
			case 8:
				cout << "Exiting program. Goodbye!" << endl;
				break;
			default:
				cout << "Invalid choice. Please pick a valid option from the menu." << endl;
				break;
		}

		cout << "\nPick a choice: ";
		cin >> choice;

	} while (choice != 8);
	
}
int main()
{
	menu();

	/* TEST block 1: Passed  // undo me to run Test 1
	* create driver
	* add tickets and locations to respective miniVectors
	* retrieve and print out driver info
	* retrieve and print ticket and location information
	* create driver and hashtable and insert multiple drivers
	* display hashtable contents
	* search drivers by name and print
	
	cout << "Adding a driver and testing the functionality of the Driver class" << endl;
	Driver d1(17, "John Doe", "New York", Date(1990, 5, 15), Date(2010, 6, 20), experienceLevel::Advanced, workStatus::PrivateSector);
	// test to make sure i can add tickets and locations to the driver
	// adding some tickets to the driver and some frequent locations

	d1.addTicket(Ticket("New York County", Date(2022, 3, 10)));
	d1.addTicket(Ticket("Kings County", Date(2023, 7, 5)));
	d1.addTicket(Ticket("Queens County", Date(2024, 1, 20)));

	d1.addLocation(Address("New York", "5th Avenue", 123, 10001));
	d1.addLocation(Address("New York", "Madison Avenue", 456, 10022));

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

	// print out the frequent locations
	cout << "Frequent Locations: " << endl;
	d1.printFrequentLocations();

	// create a hashtable with capacity of 10 and insert drivers
	CHashTable driverDB(10);
	driverDB.insert("Jane Smith", Driver(25, "Jane Smith", "Los Angeles", Date(1995, 8, 20), Date(2015, 9, 15), experienceLevel::Intermediate, workStatus::SelfEmployed));
	driverDB.insert("Bob Johnson", Driver(40, "Bob Johnson", "Chicago", Date(1980, 12, 5), Date(2000, 1, 10), experienceLevel::Advanced, workStatus::GovernmentEmployee));
	driverDB.insert("Alice Williams", Driver(30, "Alice Williams", "Houston", Date(1990, 3, 25), Date(2010, 4, 30), experienceLevel::Intermediate, workStatus::BusinessOwnder));
	driverDB.insert("Charlie Brown", Driver(22, "Charlie Brown", "Phoenix", Date(2000, 6, 10), Date(2020, 7, 15), experienceLevel::Beginner, workStatus::Student));

	// display the contents of the hashtable
	driverDB.display(); 
	
	// search for a driver by name
	Driver* searchResult = driverDB.search("Alice Williams");

	// print out search result
	cout << "Search Result for 'Alice Williams': " << endl;
	cout << "Name: " << searchResult->getName() << ", Age: " << searchResult->getAge()
		<< ", Work City: " << searchResult->getWorkCity() << endl;
	// undo me to run Test 1 -> */ 
	

	/* <- undo me to run Test 2  
	TEST BLOCK 2: sorting drivers by license issue date (needed fix)
	* Add drivers with different license issue dates to a miniVector
	* print before sort and after
	* retrieve most recent 3 drivers from sorted vector and print their names
	* 
	* TODO: fix sort
	
	miniVector<Driver> drivers;

	// Add drivers with different license dates
	drivers.add(Driver(25, "Alice", "NY", Date(1998, 1, 1), Date(2020, 5, 10), experienceLevel::Beginner, workStatus::Student));
	drivers.add(Driver(30, "Bob", "LA", Date(1995, 2, 2), Date(2015, 3, 20), experienceLevel::Intermediate, workStatus::PrivateSector));
	drivers.add(Driver(40, "Charlie", "TX", Date(1985, 3, 3), Date(2010, 7, 15), experienceLevel::Advanced, workStatus::GovernmentEmployee));
	drivers.add(Driver(22, "Daisy", "FL", Date(2002, 4, 4), Date(2022, 1, 5), experienceLevel::Beginner, workStatus::Student));

	cout << "=== BEFORE SORT ===" << endl;
	printDrivers(drivers);

	// Sort by license issue date (oldest → newest)
	sortByLicense(drivers);

	cout << "\n=== AFTER SORT (Oldest → Newest) ===" << endl;
	printDrivers(drivers);
	
	// retrieve 3 most recent from drivers
	for (size_t i = 3; i > 0; i--)
	{
		cout << int(i) << ". " << drivers.get(i).getName() << endl;
	} 
	*/

	/*  <- undo me to run Test 3
	* TEST BLOCK 3: loading driver data from CSV file and interacting with hashtable
	* creates hashtable and miniVector to store driver data
	* load driver data from CSV
	* display hashtable contents and size of miniVector
	* test search function of hashtable

	CHashTable driverDB2(50);
	miniVector<Driver> driverList;

	loadDriversFromCSV("drivers_100_test_data.csv", driverDB, driverList);

	cout << "\n=== HASH TABLE ===\n";
	driverDB.display();

	cout << "\n=== VECTOR SIZE ===\n";
	cout << driverList.getSize() << endl;

	// test search
	Driver* result = driverDB.search("Liam Anderson");

	if (result != nullptr)
	{
		cout << "\nSearch:\n";
		cout << result->getName() << " | " << result->getWorkCity() << endl;
	}
	undo me to run Test 3 ->*/
                               
	

	return 0;                                      
	// 4. menu system to interact w hashtable DB   
	// 		- upload driver data from file          
	// 		- search for driver by name         
	// 		- add ticket to driver
	// 		- add frequent location to driver
	//      - remove and add to inactive drivers DB 
	// 5. makefile 
}