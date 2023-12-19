# HWS_r_d_GameDev
#### Key Functions and Modules

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
