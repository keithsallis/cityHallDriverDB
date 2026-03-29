#include "loadFile.h"

experienceLevel parseExperience(const string& s)
{
    if (s == "Beginner") return experienceLevel::Beginner;
    if (s == "Intermediate") return experienceLevel::Intermediate;
    return experienceLevel::Advanced;
}

workStatus parseWorkStatus(const string& s)
{
    if (s == "GovernmentEmployee") return workStatus::GovernmentEmployee;
    if (s == "SelfEmployed") return workStatus::SelfEmployed;
    if (s == "Student") return workStatus::Student;
    if (s == "BusinessOwnder") return workStatus::BusinessOwnder;
    return workStatus::PrivateSector;
}

void loadDriversFromCSV(
    const string& filename,
    CHashTable& driverDB,
    miniVector<Driver>& driverList)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;

    // skip header
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);

        string ageStr, name, workCity;
        string bd, bm, by;
        string ld, lm, ly;
        string expStr, statusStr;

        getline(ss, ageStr, ',');
        getline(ss, name, ',');
        getline(ss, workCity, ',');
        getline(ss, bd, ',');
        getline(ss, bm, ',');
        getline(ss, by, ',');
        getline(ss, ld, ',');
        getline(ss, lm, ',');
        getline(ss, ly, ',');
        getline(ss, expStr, ',');
        getline(ss, statusStr, ',');

        int age = stoi(ageStr);

        Date dob(stoi(bd), stoi(bm), stoi(by));
        Date license(stoi(ld), stoi(lm), stoi(ly));

        Driver d(
            age,
            name,
            workCity,
            dob,
            license,
            parseExperience(expStr),
            parseWorkStatus(statusStr)
        );

        // store in both structures
        driverDB.insert(name, d);
        driverList.add(d);
    }
    file.close();
    cout << "Drivers loaded successfully.\n";
}