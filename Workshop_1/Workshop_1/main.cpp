#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));
    const int GeneratingRange = 50;
    
    int guessedNum = -2;
    int numOfGuesses = 0;
    int highscore = 0;
    
    std::cout << "WELCOME TO SUPER GAME OF NUMBER's GUESSING CHALLANGE!" << std::endl;
    std::cout << "I'm (SUPER COMPUTER BRAIN) GENERATING, you (regular human) GUESS!" << std::endl;
    
    
    while(guessedNum != -1){
        std::cout << std::endl;
        numOfGuesses = 0;
        guessedNum = -2;
        const double generatedNum = std::rand() % (GeneratingRange + 1);
        
        std::cout << "Generating random number from 0 to 50..." << std::endl;
        std::cout << "Enter -1 to give up!" << std::endl;
        while(guessedNum != generatedNum){
            numOfGuesses++;
            std::cout << std::endl;
            std::cout << "Make your guess: ";
            std::cin >> guessedNum;
            if(guessedNum == -1){
                std::cout << std::endl;
                std::cout << "ALREADY GIVING UP???" << std::endl;
                std::cout << "HA-HA-HA!!! COME BACK WHEN U'LL BE MORE BRAVE!" << std::endl;
                break;
            }else if(guessedNum == generatedNum){
                std::cout << std::endl;
                std::cout << "!!! CONGRATS !!! " << generatedNum << " WAS MY GUESS INDEED !!!" << std::endl;
                std::cout << "You spent " << numOfGuesses <<" tries!";
                if(highscore == 0 || highscore > numOfGuesses){
                    highscore = numOfGuesses;
                }
                std::cout << "Your highscore is " << highscore <<" tries!";
                std::cout << std::endl;
                break;
            }
            if (guessedNum > 50 || guessedNum < -1){
                std::cout << "LOL!!! I SAID THE NUMBER IS FROM 0 TO 50!!!" << std::endl;
            } else {
                if (guessedNum > generatedNum){
                    if(guessedNum - generatedNum < 5){
                        std::cout << "Try just a little bit smaller!" << std::endl;
                    }else if(guessedNum - generatedNum > 15){
                        std::cout << "Way too high! Try smaller!" << std::endl;
                    }
                    else{
                        std::cout << "Try smaller!" << std::endl;
                    }
                }else{
                    if(generatedNum - guessedNum < 5){
                        std::cout << "Try just a little bit higher!" << std::endl;
                    }else if(generatedNum - guessedNum > 15){
                        std::cout << "Way too small! Try higher!" << std::endl;
                    }
                    else{
                        std::cout << "Try higher!" << std::endl;
                    }
                }
            }
        }
    }
}
