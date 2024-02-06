#pragma once
#include <cstdlib>
#include <cstddef>
#include <stdexcept>


template <typename T>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(std::size_t size);
    DynamicArray(const DynamicArray& other);   //c-py c-tor, #TODO,change signature if needed

    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other); //assignment operator, #TODO, change signature if needed

    //validate index always or only in _DEBUG configuration done
    T& operator[](std::size_t index);

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();

    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    // done
    void push_back(const T& element);

    //#TODO: HW new methods
    void pop_back();    //remove last element
    T back() const;   //get last element

    //https://cplusplus.com/reference/vector/vector/reserve/
    //used to allocate more memory than needed right now
    //to greatly decrease the number of heap calls for memory reallocation
    //and the number of operations to copy old data to the new memory chunk
    void reserve(std::size_t reservedSpace);    
    std::size_t getCapacity() const;    //returns reserve size. Should be ALWAYS >= than actual size

    //reduce the capacity to fit its size
    //https://cplusplus.com/reference/vector/vector/shrink_to_fit/
    void shrinkToFit();

    bool operator==(const DynamicArray& other) const;    //#TODO, change signature if needed
private:
    T* array;
    std::size_t size;
    std::size_t capacity;
};

// Implementation of the template class methods goes here
template <typename T>
DynamicArray<T>::DynamicArray() : array(nullptr), size(0), capacity(0) {}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
}

template <typename T>
std::size_t DynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
T& DynamicArray<T>::operator[](std::size_t index)
{
#ifdef _DEBUG
    // Validate index in debug configuration
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
#endif
    return array[index];
}

template <typename T>
void DynamicArray<T>::push_back(const T& element)
{
    // Allocate new memory for the larger container
    T* new_array = new T[size + 1];

    // Copy old elements to the new array
    std::copy(array, array + size, new_array);

    // Insert the new element at the last index
    new_array[size] = element;

    // Deallocate the old memory
    delete[] array;

    // Update data pointer to the new array
    array = new_array;

    // Update size
    size++;
}

template <typename T>
void DynamicArray<T>::pop_back()
{
#ifdef _DEBUG
    if (size == 0) {
        throw std::logic_error("Cannot pop_back from an empty DynamicArray");
    }
#endif
    // Deallocate memory for the last element
    array[size - 1].~T();
    // Reduce the size
    size--;
}

template <typename T>
T DynamicArray<T>::back() const
{
#ifdef _DEBUG
    if (size == 0) {
        throw std::logic_error("Cannot get last element from an empty DynamicArray");
    }
#endif
    // Return a copy of the last element
    return array[size - 1];
}

template <typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace)
{
    if (reservedSpace <= capacity) {
        return; // No need to reallocate memory
    }
    // Allocate new memory for the larger container
    T* new_array = new T[reservedSpace];
    // Copy old elements to the new array
    std::copy(array, array + size, new_array);
    // Deallocate the old memory
    delete[] array;
    // Update data pointer to the new array
    array = new_array;
    // Update capacity
    capacity = reservedSpace;
}

template <typename T>
std::size_t DynamicArray<T>::getCapacity() const
{
    return capacity;
}

template <typename T>
void DynamicArray<T>::shrinkToFit()
{
    if (size == capacity) {
        return; // No extra capacity to shrink
    }
    // Allocate new memory for the smaller container
    T* new_array = new T[size];
    // Copy old elements to the new array
    std::copy(array, array + size, new_array);
    // Deallocate the old memory
    delete[] array;
    // Update data pointer to the new array
    array = new_array;
    // Update capacity to match the size
    capacity = size;
}
