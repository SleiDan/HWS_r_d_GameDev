#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool calculateSum(const double* arr, int arrSize, double& sum) {
    if (arrSize <= 0) {
        return false;
    }

    sum = 0.0;
    for (int i = 0; i < arrSize; ++i) {
        sum += arr[i];
    }

    return true;
}

bool find(const int* arr, int size, int elem) {
    const int* end = arr + size;
    while (arr < end) {
        if (*arr == elem) {
            return true;
        }
        ++arr;
    }

    return false;
}

int main() {
    std::cout << "TASK1" << std::endl;
    int x = 5, y = 10;
    std::cout << "Before swap (by reference): x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap (by reference): x = " << x << ", y = " << y << std::endl;
    std::cout << std::endl;

    int p = 15, q = 20;
    std::cout << "Before swap (by pointer): p = " << p << ", q = " << q << std::endl;
    swap(&p, &q);
    std::cout << "After swap (by pointer): p = " << p << ", q = " << q << std::endl;
    std::cout << std::endl;

    std::cout << "TASK2" << std::endl;
    double array[] = {1.5, 2.5, 3.5, 4.5};
    double sum = 0.0;
    int arraySize = sizeof(array) / sizeof(array[0]);
    bool sumResult = calculateSum(array, arraySize, sum);
    std::cout << "Sum of array elements: " << (sumResult ? sum : 0.0) << std::endl;
    std::cout << std::endl;

    std::cout << "TASK3" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    int searchNumber = 3;
    bool findResult = find(numbers, sizeof(numbers) / sizeof(numbers[0]), searchNumber);
    std::cout << "Number " << searchNumber << " " << (findResult ? "found" : "not found") << " in the array." << std::endl;

    return 0;
}
