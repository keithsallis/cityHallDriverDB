#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class miniVector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity);
public:
	// Constructor, Destructor
    miniVector();
    ~miniVector();

	// Member functions
    void add(const T& value);
    void erase(int idx);
    
	// getters and setters
    T get(int idx) const;
    void set(int idx, const T& value);
    int getSize() const;
};