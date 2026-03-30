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
		int years = 0; // default for SeniorDriver

        Date dob(stoi(bd), stoi(bm), stoi(by));
        Date license(stoi(ld), stoi(lm), stoi(ly));

        // if driver is unfit make them an unfit driver
        
		// create appropriate Driver object based on age
        if(age < 25) {
            YouthDriver yd(age, name, workCity, dob, license, false);
            driverDB.insert(name, yd);
            driverList.add(yd);
            continue;
        } else if (age >= 25 && age < 60) {
            MiddleAgedDriver md(age, name, workCity, dob, license);
            driverDB.insert(name, md);
            driverList.add(md);
            continue;
		}
        else if (age >= 60) {
            SeniorDriver sd(age, name, workCity, dob,license, years);
            driverDB.insert(name, sd);
            driverList.add(sd);
            continue;
		}
    }
    file.close();
    cout << "Drivers loaded successfully.\n";
}