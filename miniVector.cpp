#include "miniVector.h"
// Constructor
template <typename T>
miniVector<T>::miniVector() : data(nullptr), size(0), capacity(0) {}

// Destructor
template <typename T>
miniVector<T>::~miniVector() {
	delete[] data;
}

// Member functions
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

// Getters and setters
template <typename T>
T miniVector<T>::get(int idx) const {
	if (idx < 0 || idx >= size) {
		throw out_of_range("Index out of range");
	}
	return data[idx];
}

template <typename T>
void miniVector<T>::set(int idx, const T& value) {
	if (idx < 0 || idx >= size) {
		throw out_of_range("Index out of range");
	}
	data[idx] = value;
}

template <typename T>
int miniVector<T>::getSize() const {
	return size;
}


