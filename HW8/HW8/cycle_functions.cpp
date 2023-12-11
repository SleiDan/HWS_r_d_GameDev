#include <iostream>
#include "cycle_functions.h"


void num_of_nums(int a){
    int num = 0;
    int numOfPositives = 0, numOfNegatives = 0, numOfZeros = 0;
    for(int i = 0; i < a; i++){
        std::cout << "Enter " << i + 1 << " number: ";
        std::cin >> num;
        if(num == 0){
            numOfZeros++;
        }else if(num < 0){
            numOfNegatives++;
        }else{
            numOfPositives++;
        }
    }
    std::cout << "Positive: " << numOfPositives << ", negative: " << numOfNegatives << ", zeroes: " << numOfZeros << std::endl;

}

int factorialB(int count){
    int result = 1;
        for (int i = 2; i <= count; ++i) {
            result *= i;
        }
        return result;
}


void printNaturalNumbersA(int count){
    for(int i = count; i > 0; i--){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void printNaturalNumbersB(int count){
    for(int i = 1; i <= count; i++){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
