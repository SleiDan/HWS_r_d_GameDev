#include <iostream>
#include "recursive_functions.h"


int factorialA(int count){
    if (count == 0 || count == 1) {
            return 1;
        } else {
            return count * factorialA(count - 1);
        }
}

void printNaturalNumbersC(int count){
    if(count == 0){
        return;
    }
    std::cout << count << " ";
    printNaturalNumbersC(count - 1);
}

void printNaturalNumbersD(int count) {
    if (count > 0) {
        printNaturalNumbersD(count - 1);
        std::cout << count << " ";
    } else {
        std::cout << std::endl;
    }
}
