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
    void erase(size_t idx);
    T get(size_t idx) const;
    void set(size_t idx, const T& value);
    size_t getSize() const;
    T& getRef(size_t idx);

};

template <typename T>
miniVector<T>::miniVector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
miniVector<T>::~miniVector() {
    delete[] data;
}

template <typename T>
void miniVector<T>::resize(size_t new_capacity)
{
    T* new_data = new T[new_capacity];

    for (size_t i = 0; i < size && i < new_capacity; ++i) {
        new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

template <typename T>
void miniVector<T>::add(const T& value)
{
    // checks capacity 
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }

    data[size++] = value;
}

template <typename T>
void miniVector<T>::erase(size_t idx)
{
    if (idx < 0 || idx >= size) {
        throw out_of_range("Index out of range");
    }

    for (int i = idx; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }

    --size;
}

template <typename T>
T miniVector<T>::get(size_t idx) const
{
    if (idx < 0 || idx >= size) {
        throw out_of_range("Index out of range");
    }
    return data[idx];
}

template <typename T>
void miniVector<T>::set(size_t idx, const T& value)
{
    if (idx < 0 || idx >= size) {
        throw out_of_range("Index out of range");
    }
    data[idx] = value;
}

template <typename T>
size_t miniVector<T>::getSize() const
{
    return size;
}

template <typename T>
T& miniVector<T>::getRef(size_t idx)
{
    if (idx >= size) {
        throw out_of_range("Index out of range");
    }
    return data[idx];
}