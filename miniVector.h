#pragma once
#include <iostream>

using namespace std;

template <typename T>
class miniVector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity);

public:
    miniVector();
    ~miniVector();

    void add(const T& value);
    void erase(int idx);

    T get(int idx) const;
    void set(int idx, const T& value);
    size_t getSize() const;
};

template <typename T>
miniVector<T>::miniVector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
miniVector<T>::~miniVector() {
    delete[] data;
}

// Private method to resize the internal array
template <typename T>
void miniVector<T>::resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];

    for (size_t i = 0; i < size && i < new_capacity; ++i) {
        new_data[i] = data[i]; 
    } 

    delete[] data;
    data = new_data;
    capacity = new_capacity;
}
// add and erase
template <typename T>
void miniVector<T>::add(const T& value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template <typename T>
void miniVector<T>::erase(int idx) {
    if (idx < 0 || idx >= size) {
        throw out_of_range("Index out of range");
    }
    for (int i = idx; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

// getters and setter
template <typename T>
T miniVector<T>::get(int idx) const {
    if (idx < 0 || idx >= size) {
        throw out_of_range("Index out of range");
    }
    return data[idx];
}

template <typename T>
size_t miniVector<T>::getSize() const {
    return size;
}

template <typename T>
void miniVector<T>::set(int idx, const T& value) {
    if (idx < 0 || idx >= size) {
        throw out_of_range("Index out of range");
    }
    data[idx] = value;
}

