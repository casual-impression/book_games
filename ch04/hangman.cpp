#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to display the hangman ASCII art based on the number of incorrect guesses
void displayHangman(int incorrectGuesses) {
    std::vector<std::string> hangman = {
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========",
        
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "=========",
        
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "========="
    };

    std::cout << hangman[incorrectGuesses] << std::endl;
}

// Function to check if the guessed letter is in the hidden word
bool isLetterInWord(char letter, const std::string& word) {
    for (char c : word) {
        if (c == letter) {
            return true;
        }
    }
    return false;
}

// Function to update the display word with correctly guessed letters
void updateDisplayWord(char letter, const std::string& word, std::string& displayWord) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            displayWord[i] = letter;
        }
    }
}

int main() {
    std::vector<std::string> words = {"hangman", "computer", "science", "programming", "challenge"};
    srand(time(0));
    std::string word = words[rand() % words.size()];
    std::string displayWord(word.length(), '-');
    int incorrectGuesses = 0;
    std::vector<char> guessedLetters;

    std::cout << "Welcome to Hangman!" << std::endl;

    while (incorrectGuesses < 6) {
        std::cout << std::endl;
        displayHangman(incorrectGuesses);
        std::cout << "Word: " << displayWord << std::endl;
        std::cout << "Guessed letters: ";
        for (char c : guessedLetters) {
            std::cout << c << " ";
        }
        std::cout << std::endl;

        char guess;
        std::cout << "Guess a letter: ";
        std::cin >> guess;

        // Check if the guessed letter has been guessed before
        if (std::find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            std::cout << "You already guessed that letter!" << std::endl;
            continue;
        }

        guessedLetters.push_back(guess);

        // Check if the guessed letter is in the word
        if (isLetterInWord(guess, word)) {
            updateDisplayWord(guess, word, displayWord);
            if (displayWord == word) {
                std::cout << std::endl;
                std::cout << "Congratulations! You guessed the word: " << word << std::endl;
                break;
            }
        } else {
            incorrectGuesses++;
        }
    }

    if (incorrectGuesses == 6) {
        std::cout << std::endl;
        displayHangman(6);
        std::cout << "Sorry, you lost! The word was: " << word << std::endl;
    }

    return 0;
}