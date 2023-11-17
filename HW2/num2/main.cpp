#include <iostream>
#include <iomanip>
#include <ostream>

int main() {
    //first task
    std::cout << "TASK NUMBER 1" << std::endl;
    int integer1;
    int integer2;
    std::cout << "Enter integer 1: ";
    std::cin >> integer1;
    std::cout << "Enter integer 2: ";
    std::cin >> integer2;
    int temp = integer1;
    integer1 = integer2;
    integer2 = temp;
    std::cout << "Integer1: " << integer1 << std::endl;
    std::cout << "Integer2: " << integer2 << std::endl;
    std::cout << std::endl;
    
    //second task
    std::cout << "TASK NUMBER 2" << std::endl;
    double double1 = 2.34334;
    std::cout << "Printning double as double: " << double1 << std::endl;
    std::cout << "printing double as integer: " << int(double1) << std::endl;
    std::cout << "Printing third condition: " << std::setw(20) << std::setfill('$') << std::right << double1 << std::endl;
    std::cout << std::endl;

    //third task
    std::cout << "TASK NUMBER 3" << std::endl;
    double double2 = 343.0123456789321321;
    std::cout << "2 nums after point: " << std::setprecision(5) << double2 << std::endl;
    std::cout << "5 nums after point:" << std::setprecision(8) << double2 << std::endl;
    std::cout << "10 nums after point" << std::setprecision(13) << double2 << std::endl;
    std::cout << "Num as standart notation: " << std::fixed << double2 << std::endl;
    std::cout << "Num as e-notation: " << std::scientific << double2 << std::endl;
    std::cout << std::endl;

    //fourth task
    std::cout << "TASK NUMBER 4" << std::endl;
    enum class WeekDay
    {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };

    WeekDay mon = WeekDay::Monday;
    WeekDay tue = WeekDay::Tuesday;
    WeekDay wed= WeekDay::Wednesday;
    WeekDay thu = WeekDay::Thursday;
    WeekDay fri = WeekDay::Friday;
    WeekDay sat = WeekDay::Saturday;
    WeekDay sun = WeekDay::Sunday;
    
    std::cout << "Monday num: " << int(mon) << std::endl;
    std::cout << "Tuesday num: " << int(tue) << std::endl;
    std::cout << "Wednesday num: " << int(wed) << std::endl;
    std::cout << "Thursday num: " << int(thu) << std::endl;
    std::cout << "Friday num: " << int(fri) << std::endl;
    std::cout << "Saturday num: " << int(sat) << std::endl;
    std::cout << "Sunday num: " << int(sun) << std::endl;
    std::cout << std::endl;

    //fifth task
    std::cout << "TASK NUMBER 5" << std::endl;
    int integer3;
    std::cout << "Enter num for task: ";
    std::cin >> integer3;
    std::cout << "Bool integer: " << std::boolalpha << static_cast<bool>(integer3) << std::endl;
}
