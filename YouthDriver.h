#ifndef YOUTHDRIVER_H
#define YOUTHDRIVER_H

#include "Driver.h"

class YouthDriver : public Driver {
private:
    bool licenseExpired;

public:
    YouthDriver();
    YouthDriver(string name, string workCity, Date dob, bool expired);

    bool isExpired() const;
};

#endif
