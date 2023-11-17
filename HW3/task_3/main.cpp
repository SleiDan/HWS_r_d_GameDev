#include <iostream>

int main(){
    //task1
    std::cout << "TASK 1" << std::endl;
    std::cout << "Enter time: ";
    int startSecs = 0;
    std::cin >> startSecs;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    hours = startSecs / 3600;
    minutes = startSecs % 3600 / 60;
    seconds = startSecs - (hours * 3600) - (minutes * 60);
    std::cout << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." << std::endl;
    std::cout << std::endl;

    //task2
    std::cout << "TASK 2" << std::endl;
    int num1 = 0, num2 = 0, num3 = 0;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter third number: ";
    std::cin >> num3;

    std::cout << "Sum: " << num1 + num2 + num3 << std::endl;
    std::cout << "Product: " << num1 * num2 * num3 << std::endl;
    std::cout << "Arithmetic mean: " << static_cast<double>(num1 + num2 + num3) / 3 << std::endl;
    int resultBool1 = num1 > num2;
    std::cout << "The result of comparing(>) the first number with the second: " << resultBool1  << std::endl;
    if (resultBool1){
        std::cout << "Larger number among the first and second: " << num1 << std::endl;
    } else{
        std::cout << "Larger number among the first and second: " << num2 << std::endl;
    }
    int resultBool2 = num2 > num3;
    std::cout << "The result of comparing(>) the second number with the third: " << resultBool2  << std::endl;
    if (resultBool2){
        std::cout << "Larger number among the second and third: " << num2 << std::endl;
    } else{
        std::cout << "Larger number among the second and third: " << num3 << std::endl;
    }
    std::cout << std::endl;

    //task3
    std::cout << "TASK 3" << std::endl;
    int numA = 0, numB = 0;
    std::cout << "Enter first number: ";
    std::cin >> numA;
    std::cout << "Enter second number: ";
    std::cin >> numB;
    bool lessThan = numA < numB;
    bool equal = numA == numB;
    bool moreThan = numA > numB;
    bool lessOrEqual = numA <= numB;
    std::cout << numA << " lessThan " << numB << "? " << lessThan << std::endl;
    std::cout << "As word: " << std::boolalpha << lessThan << std::endl;
    std::cout << numA << " equal " << numB << "? " << std::noboolalpha << equal << std::endl;
    std::cout << "As word: " << std::boolalpha << equal << std::endl;
    std::cout << numA << " moreThan " << numB << "? " << std::noboolalpha << moreThan << std::endl;
    std::cout << "As word: " << std::boolalpha << moreThan << std::endl;
    std::cout << numA << " lessOrEqual " << numB << "? " << std::noboolalpha << lessOrEqual << std::endl;
    std::cout << "As word: " << std::boolalpha << lessOrEqual << std::endl;
    std::cout << std::endl;
    
    //task4
    std::cout << "TASK 4" << std::endl;
    int width = 0, height = 0;
    std::cout << "Enter width of the rectangle: ";
    std::cin >> width;
    std::cout << "Enter height of the rectangle: ";
    std::cin >> height;
    std::cout << "S = " << width * height << std::endl;
    std::cout << "P = " << (width + height) * 2 << std::endl;
    
    //task5
    std::cout << "TASK 5" << std::endl;
    int radius = 0;
    const double Pi = 3.14;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    std::cout << "S = " << Pi * radius * radius << std::endl;
    std::cout << "l = " << 2 * Pi * radius << std::endl;
    std::cout << std::endl;
}
