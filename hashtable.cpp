#include "hashTable.h"
#include <iostream>

#define NULL_VALUE -1 // 

CHashTable::CHashTable() 
{
    capacity = 20;
    ptr = new miniVector<Driver>[capacity];
}

// constructor
CHashTable::CHashTable(int capacity) 
{
    this->capacity = capacity;
    ptr = new miniVector<Driver>[capacity];
}

// destructor
CHashTable::~CHashTable() 
{
    delete[] ptr;
}

// function to insert driver based on string key aka name
void CHashTable::insert(string key, Driver driver) 
{
    int index = keyFunction.m_Adler32HashFunction(key, capacity);
	ptr[index].add(driver);
}

// function to read driver based on key
Driver* CHashTable::search(string key)
{
    int index = keyFunction.m_Adler32HashFunction(key, capacity);

    for (size_t i = 0; i < ptr[index].getSize(); ++i) {
        if (ptr[index].getRef(i).getName() == key) {
            return &ptr[index].getRef(i);
        }
    }
    cout << "Driver with name '" << key << "' not found." << endl;
    return nullptr;
}

void CHashTable::display() 
{
    for (int i = 0; i < capacity; ++i) {
        for (size_t j = 0; j < ptr[i].getSize(); ++j) {
            Driver driver = ptr[i].get(j);
            cout << "Name: " << driver.getName() << ", Age: " << driver.getAge() 
                 << ", Work City: " << driver.getWorkCity() << endl;
        }
	}
}