#ifndef SENIORDRIVER_H
#define SENIORDRIVER_H

#include "Driver.h"

class SeniorDriver : public Driver {
private:
    int yearsWithoutTicket;

public:
    SeniorDriver();
    SeniorDriver(string name, string workCity, Date dob, int years);

    bool discountEligible() const;
    void operations();
};

#endif
