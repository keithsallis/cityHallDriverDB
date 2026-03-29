#pragma once
#include <fstream>
#include <sstream>
#include "hashTable.h"

experienceLevel parseExperience(const string& s);
workStatus parseWorkStatus(const string& s);
void loadDriversFromCSV(const string& filename, CHashTable& driverDB, miniVector<Driver>& driverList);