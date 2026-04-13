#include "YouthDriver.h"

YouthDriver::YouthDriver() : licenseExpired(false) {}

YouthDriver::YouthDriver(string name, string workCity, Date dob, bool expired)
    : Driver(name, workCity, dob), licenseExpired(expired) {}

bool YouthDriver::isExpired() const {
    return licenseExpired;
}
