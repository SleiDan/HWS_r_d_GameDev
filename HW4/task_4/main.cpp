#include <iostream>

int main() {
    //TASK 1
    std::cout << "TASK 1" << std::endl;
    int num1 = 0, num2 = 0, num3 = 0;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter third number: ";
    std::cin >> num3;

    if (num1 > num2)
    {
        if (num1 > num3)
        {
            std::cout << num1 << " is the largest number" << std::endl;
        }
        else
        {
            std::cout << num3 << " is the largest number" << std::endl;
        }
    }
    else
    {
        if (num2 > num3)
        {
            std::cout << num2 << " is the largest number" << std::endl;
        }
        else
        {
            std::cout << num3 << " is the largest number" << std::endl;
        }
    }
    std::cout << std::endl;

    //TASK 2
    std::cout << "TASK 2" << std::endl;
    int numA = 0, numB = 0;
    std::cout << "Enter first number: ";
    std::cin >> numA;
    std::cout << "Enter second number: ";
    std::cin >> numB;

    int minimum = (numA < numB) ? numA : numB;
    std::cout << minimum << " is minimum" << std::endl;
    std::cout << std::endl;

    //TASK 3
    std::cout << "TASK 3" << std::endl;
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;

    if (num % 5 == 0 && num % 11 == 0)
    {
        std::cout << num << " can be divided by 5 and 11" << std::endl;
    }
    else if (num % 5 != 0 && num % 11 == 0)
    {
        std::cout << num << " can't be divided by 5 but can be divided 11" << std::endl;
    }
    else if (num % 5 == 0 && num % 11 != 0)
    {
        std::cout << num << " can't be divided by 11 but can be divided 5" << std::endl;
    }
    else
    {
        std::cout << num << " can't be divided by 5 and 11" << std::endl;
    }
    std::cout << std::endl;


    //TASK 4
    std::cout << "TASK 4" << std::endl;
    int angle1 = 0, angle2 = 0, angle3 = 0;
    std::cout << "Enter first angle: ";
    std::cin >> angle1;
    std::cout << "Enter second angle: ";
    std::cin >> angle2;
    std::cout << "Enter third angle: ";
    std::cin >> angle3;

    if (angle1 <= 0 || angle2 <= 0 || angle3 <= 0)
    {
        std::cout << "Angle can't be negative!" << std::endl;
    }
    else if (angle1 + angle2 + angle3 == 180)
    {
        std::cout << "You can make triangle with this angles" << std::endl;
    }
    else
    {
        std::cout << "You can't make triangle with this angles" << std::endl;
    }
    std::cout << std::endl;


    //TASK 5
    std::cout << "TASK 5" << std::endl;

    enum class Month
    {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    int numOfMonth = 0;
    std::cout << "Choose a month (from 1 to 12): ";
    std::cin >> numOfMonth;

    Month chosenMonth = static_cast<Month>(numOfMonth);



    switch (chosenMonth)
    {
    case Month::January:
        std::cout << "You chose: ";
        std::cout << "January" << std::endl;
        break;
    case Month::February:
        std::cout << "You chose: ";
        std::cout << "February" << std::endl;
        break;
    case Month::March:
        std::cout << "You chose: ";
        std::cout << "March" << std::endl;
        break;
    case Month::April:
        std::cout << "You chose: ";
        std::cout << "April" << std::endl;
        break;
    case Month::May:
        std::cout << "You chose: ";
        std::cout << "May" << std::endl;
        break;
    case Month::June:
        std::cout << "You chose: ";
        std::cout << "June" << std::endl;
        break;
    case Month::July:
        std::cout << "You chose: ";
        std::cout << "July" << std::endl;
        break;
    case Month::August:
        std::cout << "You chose: ";
        std::cout << "August" << std::endl;
        break;
    case Month::September:
        std::cout << "You chose: ";
        std::cout << "September" << std::endl;
        break;
    case Month::October:
        std::cout << "You chose: ";
        std::cout << "October" << std::endl;
        break;
    case Month::November:
        std::cout << "You chose: ";
        std::cout << "November" << std::endl;
        break;
    case Month::December:
        std::cout << "You chose: ";
        std::cout << "December" << std::endl;
        break;
    default:
        std::cout << "The entered number does not correspond to any month" << std::endl;
        break;
    }
    std::cout << std::endl;

    //TASK 6
    std::cout << "TASK 6" << std::endl;

    int month = 0;
    std::cout << "Choose a month (from 1 to 12): ";
    std::cin >> month;

    switch (month) {
    case 1:
    case 2:
    case 12:
        std::cout << "Winter" << std::endl;
        break;
    case 3:
    case 4:
    case 5:
        std::cout << "Spring" << std::endl;
        break;
    case 6:
    case 7:
    case 8:
        std::cout << "Summer" << std::endl;
        break;
    case 9:
    case 10:
    case 11:
        std::cout << "Autumn" << std::endl;
        break;
    default:
        std::cout << "The entered number does not correspond to any season" << std::endl;
        break;
    }
}
