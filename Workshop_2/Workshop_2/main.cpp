#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <algorithm>
#include <ctime>

const int maxWordLength = 5;

int getDay(const std::tm* tmObj)
{
    return tmObj->tm_mday;
}

int getMonth(const std::tm* tmObj)
{
    return tmObj->tm_mon + 1;
}

int getYear(const std::tm* tmObj)
{
    return tmObj->tm_year + 1900;
}

int countWords(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Can't open the file " << filename << std::endl;
        return -1;
    }

    int wordCount = 0;
    std::string word;

    while (file >> word) {
        ++wordCount;
    }

    file.close();
    return wordCount;
}

char** createWordArray(int wordCount) {
    char** words = new char* [wordCount];
    for (int i = 0; i < wordCount; ++i) {
        words[i] = new char[maxWordLength + 1]; // +1 because we take into account the null character of the line termination ('\0')
    }
    return words;
}

void readAndStoreWords(const std::string& filename, char** words, int wordCount) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Can't open the file " << filename << std::endl;
        return;
    }

    for (int i = 0; i < wordCount; ++i) {
        file >> std::setw(maxWordLength + 1) >> words[i];
    }

    file.close();
}

void deleteWordArray(char** words, int wordCount) {
    for (int i = 0; i < wordCount; ++i) {
        delete[] words[i];
    }
    delete[] words;
}

void compareAndUpdateResult(const char* wordInWords, const char* wordToCompare, char* result, bool& isEqual) {
    char wordInWordsLower[maxWordLength];
    char wordToCompareLower[maxWordLength];
    int doNotCheckIndecses[maxWordLength] = { -1, -1, -1, -1, -1 };
    for (int i = 0; i < maxWordLength; i++) {
        wordInWordsLower[i] = std::tolower(wordInWords[i]);
        wordToCompareLower[i] = std::tolower(wordToCompare[i]);
    }

    isEqual = std::equal(wordInWordsLower, wordInWordsLower + maxWordLength, wordToCompareLower);

    if (isEqual) {
        return;
    }
    int q = 0;
    for (int i = 0; i < maxWordLength; ++i) {
        if (wordInWordsLower[i] == wordToCompareLower[i]) {
            result[i] = std::toupper(wordToCompareLower[i]);
            doNotCheckIndecses[q] = i;
            q++;
        }
    }

    for (int i = 0; i < maxWordLength; ++i) {
        if (result[i] == '*') {
            for (int j = 0; j < maxWordLength; ++j) {
                if (wordInWordsLower[j] == wordToCompareLower[i] && !std::count(std::begin(doNotCheckIndecses), std::end(doNotCheckIndecses), j)) {
                    result[i] = wordToCompareLower[i];
                    doNotCheckIndecses[q] = j;
                    q++;
                    break;
                }
            }
        }
    }
}


int main() {

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    std::string filename = "database.txt";

    int totalWords = countWords(filename);
    if (totalWords == -1) {
        return 1;
    }

    char** words = createWordArray(totalWords);

    readAndStoreWords(filename, words, totalWords);

    std::string secondFilename = "wordsOfTheDay.txt";

    int secondTotalWords = countWords(secondFilename);
    if (secondTotalWords == -1) {
        return 1;
    }

    char** wordsOfTheDay = createWordArray(secondTotalWords);

    readAndStoreWords(secondFilename, wordsOfTheDay, secondTotalWords);

    std::string testCaseFilename = "testCases.txt";

    int testCaseTotalWords = countWords(testCaseFilename);
    if (testCaseTotalWords == -1) {
        return 1;
    }

    char** testCaseWords = createWordArray(testCaseTotalWords);

    readAndStoreWords(testCaseFilename, testCaseWords, testCaseTotalWords);

    int pathOfProg = 0;
    int counter = 0;
    char result[] = "*****";
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::unordered_set<int> usedIndices;

    while (true) {
        std::cout << "1 - Wordle of the day" << std::endl;
        std::cout << "2 - Random Wordle" << std::endl;
        std::cout << "3 - Test cases" << std::endl;
        std::cout << "0 - Exit" << std::endl;
        std::cout << "Enter: ";
        std::cin >> pathOfProg;
        std::cout << std::endl;
        bool completed = false;
        if (pathOfProg == 0) {
            break;
        }
        while (pathOfProg != 0) {
            if (pathOfProg == 2) {
                if (usedIndices.size() == totalWords) {
                    std::cout << "All words have been used. Resetting." << std::endl << std::endl;
                    usedIndices.clear();
                }

                int randomIndex;
                do {
                    randomIndex = std::rand() % totalWords;
                } while (usedIndices.count(randomIndex) > 0);

                usedIndices.insert(randomIndex);

                while (true) {
                    counter++;
                    std::cout << "RESULT : ";

                    for (int i = 0; i < strlen(result); ++i) {
                        std::cout << result[i];
                    }
                    std::cout << std::endl;

                    std::cout << "ENTER  : ";
                    char word[maxWordLength+1];
                    std::cin >> word;
                    for (int i = 0; i < 5; i++) {
                        result[i] = '*';
                    }

                    compareAndUpdateResult(words[randomIndex], word, result, completed);

                    std::cout << std::endl;

                    if (completed) {
                        completed = false;
                        std::cout << "That's right!" << std::endl << "You made " << counter << " tries!" << std::endl << std::endl;
                        counter = 0;
                        break;
                    }
                }
                break;
            }
            else if (pathOfProg == 1) {
                int randomIndex;
                do {
                    randomIndex = std::rand() % secondTotalWords;
                } while (usedIndices.count(randomIndex) > 0);

                usedIndices.insert(randomIndex);

                std::string savedDate;
                std::ifstream dateFile("info.txt");

                if (dateFile >> savedDate) {
                    if (savedDate == std::to_string(getDay(now)) + "-" + std::to_string(getMonth(now)) + "-" + std::to_string(getYear(now))) {
                        std::cout << "Already found! Come back tomorrow!" << std::endl << std::endl;

                        break;
                    }
                    else {
                        dateFile.close();
                        std::ofstream outFile("info.txt");
                        outFile << std::to_string(getDay(now)) + "-" + std::to_string(getMonth(now)) + "-" + std::to_string(getYear(now)) << std::endl;
                        outFile << wordsOfTheDay[randomIndex] << std::endl;
                        outFile.close();                  
                    }
                }
                else {                 
                    dateFile.close();
                    std::ofstream outFile("info.txt");
                    outFile << std::to_string(getDay(now)) + "-" + std::to_string(getMonth(now)) + "-" + std::to_string(getYear(now)) << std::endl;
                    outFile << wordsOfTheDay[randomIndex] << std::endl;
                    outFile.close();
                }
                
                while (true) {
                    counter++;
                    std::cout << "RESULT : ";

                    for (int i = 0; i < strlen(result); ++i) {
                        std::cout << result[i];
                    }
                    std::cout << std::endl;

                    std::cout << "ENTER  : ";
                    char word[maxWordLength + 1];
                    std::cin >> word;
                    for (int i = 0; i < 5; i++) {
                        result[i] = '*';
                    }

                    compareAndUpdateResult(wordsOfTheDay[randomIndex], word, result, completed);

                    std::cout << std::endl;

                    if (completed) {
                        completed = false;
                        std::cout << "That's right!" << std::endl << "You made " << counter << " tries!" << std::endl << std::endl;
                        counter = 0;
                        break;
                    }
                }
                break;
            }
            else if (pathOfProg == 3) {
                if (usedIndices.size() == testCaseTotalWords) {
                    std::cout << "All words have been used. Resetting." << std::endl << std::endl;
                    usedIndices.clear();
                }

                int randomIndex;
                do {
                    randomIndex = std::rand() % testCaseTotalWords;
                } while (usedIndices.count(randomIndex) > 0);

                usedIndices.insert(randomIndex);

                while (true) {
                    counter++;
                    std::cout << "RESULT : ";

                    for (int i = 0; i < strlen(result); ++i) {
                        std::cout << result[i];
                    }
                    std::cout << std::endl;

                    std::cout << "ENTER  : ";
                    char word[maxWordLength + 1];
                    std::cin >> word;
                    for (int i = 0; i < 5; i++) {
                        result[i] = '*';
                    }

                    compareAndUpdateResult(testCaseWords[randomIndex], word, result, completed);

                    std::cout << std::endl;

                    if (completed) {
                        completed = false;
                        std::cout << "That's right!" << std::endl << "You made " << counter << " tries!" << std::endl << std::endl;
                        counter = 0;
                        break;
                    }
                }
                break;
                }
            else {
                if (pathOfProg != 0) {
                    std::cout << "WRONG NUMBER!!!" << std::endl;
                    std::cout << std::endl;
                }
                break;
            }
        }
    }

    deleteWordArray(words, totalWords);
    deleteWordArray(wordsOfTheDay, secondTotalWords);
    deleteWordArray(testCaseWords, testCaseTotalWords);
}