#pragma once
#include <iostream>

using namespace std;

template <typename T>
class miniVector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity)
    {
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < size && i < new_capacity; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
public:
    miniVector() : data(nullptr), size(0), capacity(0) {}

    ~miniVector() 
    {
        delete[] data;
    }

    void add(const T& value)
    {
        // checks capacity 
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }

        data[size++] = value;
    }

    void erase(size_t idx)
    {
        if (idx < 0 || idx >= size) {
            throw out_of_range("Index out of range");
        }

        for (size_t i = idx; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }

        --size;
    }

    T get(size_t idx) const
    {
        if (idx < 0 || idx >= size) {
            throw out_of_range("Index out of range");
        }
        return data[idx];
    }
    void set(size_t idx, const T& value)
    {
        if (idx < 0 || idx >= size) {
            throw out_of_range("Index out of range");
        }
        data[idx] = value;
    }

    size_t getSize() const { return size; }

    T& getRef(size_t idx)
    {
        if (idx >= size) {
            throw out_of_range("Index out of range");
        }
        return data[idx];
    }
    void setSize(size_t new_size)
    {
        if (new_size > capacity) {
            resize(new_size);
        }
		size = new_size;
    }
};

