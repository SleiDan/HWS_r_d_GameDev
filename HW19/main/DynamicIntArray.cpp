#include "DynamicIntArray.h"

DynamicIntArray::DynamicIntArray() : size(0), data(nullptr) {}

DynamicIntArray::DynamicIntArray(std::size_t size) : size(size), data(new int[size]) {}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) : size(other.size), data(new int[other.size]) {
    for (std::size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

DynamicIntArray::~DynamicIntArray() {
    delete[] data;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (std::size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

int& DynamicIntArray::operator[](std::size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

void DynamicIntArray::setSize(std::size_t newSize) {
    delete[] data;
    size = newSize;
    data = new int[size];
}

std::size_t DynamicIntArray::getSize() const {
    return size;
}

void DynamicIntArray::clear() {
    delete[] data;
    size = 0;
    data = nullptr;
}

void DynamicIntArray::push_back(int element) {
    int* newData = new int[size + 1];
    for (std::size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = element;
    delete[] data;
    data = newData;
    ++size;
}
