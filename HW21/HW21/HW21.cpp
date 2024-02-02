#include <iostream>
#include <vector>
#include <algorithm>

// Simple comparison function
bool compareByLength(const std::string& str1, const std::string& str2) {
    return str1.length() < str2.length();
}

// Functor for length-based comparison
class LengthComparator {
public:
    bool operator()(const std::string& str1, const std::string& str2) const {
        return str1.length() < str2.length();
    }
};

// Function to count numbers divisible by a given number
unsigned int countDivisibleBy(const std::vector<int>& vec, int number) {
    return std::count_if(vec.begin(), vec.end(), [number](int element) {
        return element % number == 0;
    });
}

int main() {
    std::vector<std::string> stringContainer1 = {"apple", "banana", "orange", "grape", "kiwi"};

    // Using a simple comparison function
    std::sort(stringContainer1.begin(), stringContainer1.end(), compareByLength);

    // Displaying the sorted container
    std::cout << "Sorted by length (function): ";
    for (const auto& str : stringContainer1) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> stringContainer2 = {"apple", "banana", "orange", "grape", "kiwi"};

    // Using a functor for comparison
    LengthComparator comparator;
    std::sort(stringContainer2.begin(), stringContainer2.end(), comparator);

    // Displaying the sorted container
    std::cout << "Sorted by length (functor): ";
    for (const auto& str : stringContainer2) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> stringContainer3 = {"apple", "banana", "orange", "grape", "kiwi"};

    // Using a lambda function for comparison
    std::sort(stringContainer3.begin(), stringContainer3.end(),
              [](const std::string& str1, const std::string& str2) {
                  return str1.length() < str2.length();
              });

    // Displaying the sorted container
    std::cout << "Sorted by length (lambda): ";
    for (const auto& str : stringContainer3) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int divisor = 2;

    unsigned int count = countDivisibleBy(numbers, divisor);

    std::cout << "Count of numbers divisible by " << divisor << ": " << count << std::endl;
}
