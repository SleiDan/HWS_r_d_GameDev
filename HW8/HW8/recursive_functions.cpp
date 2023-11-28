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
        std::cout << std::endl;
        return;
    }
    std::cout << count << " ";
    printNaturalNumbersC(count - 1);
}

void printNaturalNumbersD(int count, int num){
    if(num > count){
        std::cout << std::endl;
        return;
    }
    std::cout << num << " ";
    printNaturalNumbersD(count, num+1);
}
