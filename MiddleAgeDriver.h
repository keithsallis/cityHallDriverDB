#ifndef MIDDLEAGEDDRIVER_H
#define MIDDLEAGEDDRIVER_H

#include "Driver.h"

class MiddleAgedDriver : public Driver {
public:
    MiddleAgedDriver();
    MiddleAgedDriver(string name, string workCity, Date dob);

    void operations();   // Placeholder for future behavior
};

#endif
