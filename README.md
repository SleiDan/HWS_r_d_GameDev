# HWS_r_d_GameDev
### Key Functions and Modules

1. **`compareAndUpdateResult`**
   - Description: Compares the player's input word with the target word and updates the displayed result.
   - Parameters:
     - `wordInWords`: The word to be guessed.
     - `wordToCompare`: The player's input word.
     - `result`: The displayed comparison result.
     - `isEqual`: A flag indicating whether the word has been guessed.

2. **`countWords`**
   - Description: Counts the number of words in a specified file.
   - Parameters:
     - `filename`: The name of the file to analyze.

3. **`createWordArray`**
   - Description: Creates an array of words of a specified size.
   - Parameters:
     - `wordCount`: The number of words to create the array.

4. **`readAndStoreWords`**
   - Description: Reads words from a file and stores them in an array.
   - Parameters:
     - `filename`: The name of the file to read.
     - `words`: The array to store the words.
     - `wordCount`: The number of words to read.

5. **`deleteWordArray`**
   - Description: Deletes a dynamic array of words.
   - Parameters:
     - `words`: The array to delete.
     - `wordCount`: The number of words in the array.

### Algorithm

The core algorithm involves comparing the player's input with the target word and providing feedback. Here's how it works:

1. The program selects a word from the chosen mode (daily, random, or test cases).
2. The player enters a word guess.
3. The program compares each letter of the guess with the corresponding letter in the target word.
4. If a letter matches, it is revealed in the result.
5. If a letter is in the correct position, it is displayed in uppercase.
6. The player continues guessing until the word is correctly identified or the maximum attempts are reached.

### Screenshots
#### Testcases
1. **`HELLO`**
   ![Test case HELLO](screenshots/hello.png)
2. **`COCON`**
   ![Test case COCON](screenshots/cocon.png)
3. **`SPEAK`**
   ![Test case SPEAK](screenshots/speak.png)
#### Wordle of the day work
1. **`Before restart of programm`**
   ![Test case HELLO](screenshots/before.png)
2. **`After restart of programm`**
   ![Test case COCON](screenshots/after.png)
