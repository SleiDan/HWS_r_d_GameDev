#include <iostream>
#include "DynamicArray.h"

int main()
{
    DynamicArray<int> m_container;
    m_container.reserve(4);
    m_container.push_back(25); // No new heap allocations, using reserved memory
    m_container.push_back(30); // No new heap allocations, using reserved memory
    m_container.push_back(10); // No new heap allocations, using reserved memory
    m_container.push_back(39); // No new heap allocations, using reserved memory

    std::cout << "Current size: " << m_container.getSize() << std::endl;
    std::cout << "Current capacity: " << m_container.getCapacity() << std::endl;
    std::cout << "Array content: ";
    for (std::size_t i = 0; i < m_container.getSize(); ++i) {
        std::cout << m_container[i] << " ";
    }
    std::cout << std::endl;

    // Testing pop_back() and back()
    std::cout << "Popping back: " << m_container.back() << std::endl;
    m_container.pop_back();

    std::cout << "Current size after pop_back(): " << m_container.getSize() << std::endl;
    std::cout << "Current capacity after pop_back(): " << m_container.getCapacity() << std::endl;
    std::cout << "Array content: ";
    for (std::size_t i = 0; i < m_container.getSize(); ++i) {
        std::cout << m_container[i] << " ";
    }
    std::cout << std::endl;

    // Testing reserve() and getCapacity()
    m_container.reserve(8); // Allocate more memory
    std::cout << "Current size after reserve(): " << m_container.getSize() << std::endl;
    std::cout << "Current capacity after reserve(): " << m_container.getCapacity() << std::endl;
    std::cout << "Array content: ";
    for (std::size_t i = 0; i < m_container.getSize(); ++i) {
        std::cout << m_container[i] << " ";
    }
    std::cout << std::endl;

    // Testing shrinkToFit()
    m_container.shrinkToFit();
    std::cout << "Current size after shrinkToFit(): " << m_container.getSize() << std::endl;
    std::cout << "Current capacity after shrinkToFit(): " << m_container.getCapacity() << std::endl;
    std::cout << "Array content: ";
    for (std::size_t i = 0; i < m_container.getSize(); ++i) {
        std::cout << m_container[i] << " ";
    }
    std::cout << std::endl;

    // OOPS, 5th element was added
    // allocate more memory on heap
    m_container.push_back(55);

    std::cout << "Current size after pushing 55: " << m_container.getSize() << std::endl;
    std::cout << "Current capacity after pushing 55: " << m_container.getCapacity() << std::endl;
    std::cout << "Array content: ";
    for (std::size_t i = 0; i < m_container.getSize(); ++i) {
        std::cout << m_container[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
