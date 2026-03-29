#pragma once
#include "Driver.h"

inline bool isYounger(const Date& a, const Date& b)
{
	if (a.getYear() != b.getYear()) return a.getYear() > b.getYear(); 
    if (a.getMonth() != b.getMonth()) return a.getMonth() > b.getMonth();
    return a.getDay() > b.getDay();
}

inline void sortByLicense(miniVector<Driver>& drivers)
{
    size_t size = drivers.getSize();

    for (size_t i = 0; i + 1 < size; i++)
    {
        size_t min_idx = i;

        for (size_t j = i + 1; j < size; j++)
        {
            if (isYounger(drivers.get(j).getLicenseIssueDate(), drivers.get(min_idx).getLicenseIssueDate()))
            {
                min_idx = j;
            }
        }

        // swap
        if (min_idx != i)
        {
            Driver temp = drivers.get(min_idx);
            drivers.set(min_idx, drivers.get(i));
            drivers.set(i, temp);
        }
    }
}