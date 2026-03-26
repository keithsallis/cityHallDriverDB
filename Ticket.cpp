#include "Ticket.h"

// constructors
Ticket:: Ticket()
{ 
	county = "";
	dateIssued = Date();
}

Ticket::Ticket(string c, Date d)
{
	county = c;
	dateIssued = d;
}

// setters
void Ticket::setCounty(string c)
{
	county = c;
}

void Ticket::setDateIssued(Date d)
{
	dateIssued = d;
}

// getters
string Ticket::getCounty() const
{
	return county;
}

Date Ticket::getDateIssued() const
{
	return dateIssued;
}

