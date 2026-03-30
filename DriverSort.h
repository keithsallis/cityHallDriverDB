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

inline void printMostRecent(const miniVector<Driver>& drivers, size_t n)
{
    cout << "=== " << n << " Most Recent Drivers ===" << endl;
    for (size_t i = 0; i < n && i < drivers.getSize(); i++)
    {
        cout << "Name: " << drivers.get(i).getName() << "| License Issue Date: "
             << drivers.get(i).getLicenseIssueDate().getDay() << "/"
             << drivers.get(i).getLicenseIssueDate().getMonth() << "/"
             << drivers.get(i).getLicenseIssueDate().getYear() << endl;
    }
}
inline void printOldest(const miniVector<Driver>& drivers, size_t n)
{
    cout << "=== " << n << " Oldest Drivers ===" << endl;

    size_t size = drivers.getSize();

    if (n > size) n = size;

    for (size_t i = size; i > size - n; --i)
    {
        const Driver& d = drivers.get(i - 1);

        cout << "Name: " << d.getName() << "| License Issue Date: "
                << d.getLicenseIssueDate().getDay() << "/"
                << d.getLicenseIssueDate().getMonth() << "/"
                << d.getLicenseIssueDate().getYear() << endl;
    }
    
}