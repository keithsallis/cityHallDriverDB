#pragma once
#include "hashfunction.h"
#include "miniVector.h"
#include "Driver.h"

using namespace std;

class CHashTable {
private:
    int capacity;
    miniVector<Driver>* ptr;
    CHashFunction keyFunction;

public:
    CHashTable();
    CHashTable(int capacity);
    ~CHashTable();

    void insert(string key, Driver driver);
    Driver* search(string key);
    void display();
};

