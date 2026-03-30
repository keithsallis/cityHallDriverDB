#include <iostream>
#include "Date.h"

using namespace std;

class Ticket
{
private:
	string county;
	Date dateIssued;
public:
	// constructors
	Ticket();
	Ticket(string c, Date d);

	// setters
	void setCounty(string c);
	void setDateIssued(Date d);

	// getters
	string getCounty() const;
	Date getDateIssued() const;

	//function to set ticket info
	void setTicketInfo(string c, Date d);
};