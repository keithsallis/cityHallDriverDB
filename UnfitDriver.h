#ifndef UNFITDRIVER_H
#define UNFITDRIVER_H

#include "Driver.h"

class UnfitDriver : public Driver {
private:
    string medicalCondition;
    string accommodation;

public:
    UnfitDriver();
    UnfitDriver(string name, string workCity, Date dob,
                string condition, string accommodation);

    string getCondition() const;
};

#endif
