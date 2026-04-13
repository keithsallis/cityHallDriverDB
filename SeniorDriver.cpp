#include "SeniorDriver.h"

SeniorDriver::SeniorDriver()
    : Driver(), yearsWithoutTicket(0) {}

SeniorDriver::SeniorDriver(string name, string workCity, Date dob, int years)
    : Driver(name, workCity, dob), yearsWithoutTicket(years) {}

bool SeniorDriver::discountEligible() const {
    return yearsWithoutTicket >= 5;   // Example rule
}

void SeniorDriver::operations() {
}
