#include <iostream>
#include "cycle_functions.h"
#include "recursive_functions.h"


int main() {
    int numOfNums = 0;
    std::cout << "Enter num of nums: ";
    std::cin >> numOfNums;
    num_of_nums(numOfNums);
    int count = 0;
    std::cout << "Enter count: ";
    std::cin >> count;
    int ans = factorialA(count);
    std::cout << "With recursion: " << count << "! = " << ans << std::endl;
    ans = factorialB(count);
    std::cout << "With cycle: " << count << "! = " << ans << std::endl;
    int count2 = 0;
    std::cout << "Enter number of natural nums: ";
    std::cin >> count2;
    std::cout << "With cycle:" << std::endl;
    printNaturalNumbersA(count2);
    printNaturalNumbersB(count2);
    std::cout << "With recursion: " << std::endl;
    printNaturalNumbersC(count2);
    printNaturalNumbersD(count2, 1);
    
}
