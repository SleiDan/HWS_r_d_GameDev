#include <iostream>
#include <cctype>

int main() {
    
    //TASK 1
     std::cout << "TASK 1" << std::endl;
     int a1 = 0, d = 0, a_last = 0;
     std::cout << "Enter first number: ";
     std::cin >> a1;
     std::cout << "Enter step number(d): ";
     std::cin >> d;
     std::cout << "Enter third number: ";
     std::cin >> a_last;
     
     while(a1 < a_last){
     std::cout << a1 << " ";
     a1 += d;
     }
     std::cout << std::endl;
     
     //TASK 2
     std::cout << "TASK 2" << std::endl;
     int n = 0;
     std::cout << "Enter the number of the Fibonacci sequence element: ";
     std::cin >> n;
     int counter = 2;
     int a = 1, b = 1, answer = 0;
     while(counter != n){
     answer = a + b;
     a = b;
     b = answer;
     counter++;
     }
     
     std::cout << "The value of the Fibonacci sequence element " << n << " = " << answer << std::endl;
     std::cout << std::endl;
    
    //TASK 3
    std::cout << "TASK 3" << std::endl;
    int num = 0;
    bool validInput = false;
    
    do {
        std::cout << "Please enter a positive integer number: ";
        std::cin >> num;
        
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer number." << std::endl;
        }else if(num < 0){
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
        } else {
            validInput = true;
        }
    } while (!validInput);
    //Стало ну очень интересно как сделать такую проверку)
    long long ans = 1; //long long для макс факториала = 25!
    for(int i = 1; i < num; i++){
        ans *= i + 1;
    }
    std::cout << num << "! = " << ans << std::endl;
    std::cout << std::endl;
    
    //TASK 4
    std::cout << "TASK 4" << std::endl;
    int length_of_lines;
    int num_of_rows;
    std::cout << "Enter num of rows: ";
    std::cin >> num_of_rows;
    std::cout << "Enter length of lines: ";
    std::cin >> length_of_lines;

    // a.
    std::cout << "a." << std::endl;
    for (int i = num_of_rows; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


    // b.
    std::cout << "b." << std::endl;
    for (int i = 0; i < num_of_rows; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // c.
    std::cout << "c." << std::endl;
    for (int i = 0; i < num_of_rows; ++i) {
        for (int j = 0; j < length_of_lines; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // d.
    std::cout << "d." << std::endl;
    for (int i = 0; i < num_of_rows; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k < length_of_lines; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // e.
    std::cout << "e." << std::endl;
    for (int i = 1; i <= num_of_rows; ++i) {
        if (i % 2 == 1){
          for (int j = 1; j <= i; ++j) {
            std::cout << (j % 2);
          }
          std::cout << std::endl;
        }else{
          for (int j = 1; j <= i; ++j) {
            std::cout << ((j + 1) % 2);
          }
          std::cout << std::endl;
        }
      }
      std::cout << std::endl;


    //TASK 5
    std::cout << "TASK 5" << std::endl;
    char character;
    int sumOfCharacters = 0;
    
    do{
        std::cout << "Enter character (enter '.' to end programm): ";
        std::cin >> character;
        if(islower(character)){
            char uppercaseSymbol = toupper(character);
            std::cout << "Upper case letter: " << uppercaseSymbol << std::endl;
        } else if (isdigit(character)) {
            int digitValue = static_cast<int>(character) - 48;
            sumOfCharacters += digitValue;
            std::cout << "Current sum of digits: " << sumOfCharacters << std::endl;
        } else if(character != '.') {
            std::cout << "The character is not processed by the program." << std::endl;
        }
    }while (character != '.');
    
    std::cout << "The program is complete" << std::endl;
}
