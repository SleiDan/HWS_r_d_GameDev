#include "DynamicIntArray.h"
#include <iostream>



int main() {
    // Test default constructor
    DynamicIntArray arr1;
    std::cout << "Default constructor - Size: " << arr1.getSize() << std::endl;

    // Test constructor with size
    DynamicIntArray arr2(5);
    std::cout << "Constructor with size - Size: " << arr2.getSize() << std::endl;

    // Test copy constructor
    DynamicIntArray arr3(arr2);
    std::cout << "Copy constructor - Size: " << arr3.getSize() << std::endl;

    // Test operator=
    DynamicIntArray arr4;
    arr4 = arr3;
    std::cout << "Operator= - Size: " << arr4.getSize() << std::endl;

    // Test operator[]
    arr4[2] = 42;
    std::cout << "Value at index 2: " << arr4[2] << std::endl;

    std::cout << "Array:";
    for (std::size_t i = 0; i < arr4.getSize(); ++i) {
        std::cout << " " << arr4[i];
    }
    std::cout << std::endl;
    
    // Test setSize
    arr4.setSize(8);
    std::cout << "After setSize - New size: " << arr4.getSize() << std::endl;
    
    std::cout << "Array:";
    for (std::size_t i = 0; i < arr4.getSize(); ++i) {
        std::cout << " " << arr4[i];
    }
    std::cout << std::endl;
    
    // Test push_back
    arr4.push_back(99);
    std::cout << "After push_back - New size: " << arr4.getSize() << std::endl;
    std::cout << "Value at last index: " << arr4[arr4.getSize() - 1] << std::endl;

    // Test clear
    arr4.clear();
    std::cout << "After clear - Size: " << arr4.getSize() << std::endl;

    return 0;
}
