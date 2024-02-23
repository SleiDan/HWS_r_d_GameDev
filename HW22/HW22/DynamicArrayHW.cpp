#include <iostream>
#include "DynamicArray.h"

int main() {
    DynamicArray<int> m_container;
    m_container.reserve(4);
    m_container.push_back(25);
    m_container.push_back(30);
    m_container.push_back(10);
    m_container.push_back(39);

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
    m_container.reserve(8);
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

    // Testing assignment operator and clear method
    DynamicArray<int> m_copy;
    m_copy = m_container;
    std::cout << "Copied array content: ";
    for (std::size_t i = 0; i < m_copy.getSize(); ++i) {
        std::cout << m_copy[i] << " ";
    }
    std::cout << std::endl;

    m_copy.clear();
    std::cout << "After clearing, size: " << m_copy.getSize() << ", capacity: " << m_copy.getCapacity() << std::endl;

    // Testing equality operator
    if (m_container == m_copy) {
        std::cout << "m_container and m_copy are equal." << std::endl;
    } else {
        std::cout << "m_container and m_copy are not equal." << std::endl;
    }

    return 0;
}
