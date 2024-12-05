#include <iostream>
#include <cstring>
#include <cctype>


void translateArray(int numbers[], int size){
    for(int i = 0; i < size; i++){
        if(numbers[i] % 2 == 0){
            numbers[i] *= 2;
        }else{
            numbers[i] = 0;
        }
    }
}

void toUppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = toupper(str[i]);
        }
    }
}

bool isPalindrome(const char str[]) {
    int length = static_cast<int>(strlen(str));
    
    int i = 0;
    int j = length - 1;

    while (i < j) {
        
        if (tolower(str[i]) != tolower(str[j])) {
            return false;
        }

        ++i;
        --j;
    }

    return true;
}

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount) {
    vowelsCount = 0;
    consonantsCount = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        char lowercaseChar = tolower(str[i]);

        if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' ||
            lowercaseChar == 'o' || lowercaseChar == 'u') {
            ++vowelsCount;
        } else {
            ++consonantsCount;
        }
    }
}

bool isEqual(const char str1[], const char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        ++i;
    }

    return (str1[i] == '\0' && str2[i] == '\0');
}


int main() {
    const int arraySize = 10;
    int array[arraySize];
    for(int i = 0; i < arraySize; i++){
        std::cout << "Enter " << i + 1 << " number of array: ";
        std::cin >> array[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    translateArray(array, arraySize);
     
     for(int i = 0; i < arraySize; i++){
         std::cout << array[i] << " ";
     }

    const int maxSize = 100;
    char inputString[maxSize];

    std::cout << std::endl << "Enter line: ";
    std::cin.getline(inputString, maxSize);

    toUppercase(inputString);
    std::cout << inputString << std::endl;
    
    char inputString2[maxSize];

    std::cout << "Enter line: ";
    std::cin.getline(inputString2, maxSize);

    std::cout << std::boolalpha << isPalindrome(inputString2) << std::endl;
    
    char inputString3[maxSize];

    std::cout << "Enter line: ";
    std::cin.getline(inputString3, maxSize);

    int vowelsCount = 0, consonantsCount = 0;

    parseStringLetters(inputString3, vowelsCount, consonantsCount);

    std::cout << "Amount of vowels: " << vowelsCount << std::endl;
    std::cout << "Amount of consonants: " << consonantsCount << std::endl;;

    char str1[maxSize];
    char str2[maxSize];

    std::cout << "Enter first line: ";
    std::cin.getline(str1, maxSize);

    std::cout << "Enter second line: ";
    std::cin.getline(str2, maxSize);

    std::cout << std::boolalpha << isEqual(str1, str2) << std::endl;


}
