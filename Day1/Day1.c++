#include <iostream>
#include <cctype>
#include <string>

// Function declarations (signatures unchanged except line is now a reference)
void typist(std::string& line, bool& keepTyping, char& typed);
void analyzer(const std::string& line, int& numberOfWords, int& numberOfLines,
              int& spaces, std::string& longestWord, int& numberOfDigits);

int main() {
    std::string line;
    int numberOfWords = 0;
    int spaces = 0;
    int numberOfLines = 0;
    int numberOfDigits = 0;
    bool keepTyping = true;     // control flag
    char typed = 'y';
    std::string longestWord = "";  // was =0 – fixed

    std::cout << "Input your lines (type 'n' when done)\n";
    typist(line, keepTyping, typed);   // line is passed by reference

    // Now analyze the accumulated text
    analyzer(line, numberOfWords, numberOfLines, spaces, longestWord, numberOfDigits);

    // Print results (moved here from inside analyzer)
    std::cout << "\n--- Results ---\n";
    std::cout << "Number of words  : " << numberOfWords << '\n';
    std::cout << "Number of lines  : " << numberOfLines << '\n';
    std::cout << "Number of spaces : " << spaces << '\n';
    std::cout << "Number of digits : " << numberOfDigits << '\n';
    std::cout << "Longest word     : " << longestWord << '\n';

    return 0;
}

void typist(std::string& line, bool& keepTyping, char& typed) {
    // Accumulate all lines into a single string
    while (keepTyping) {
        std::string input;
        std::cout << "Enter a line: ";
        std::getline(std::cin, input);
        // Append the line and a newline to mark line boundaries
        line += input + '\n';

        std::cout << "Continue typing? (y/n): ";
        std::cin >> typed;
        std::cin.ignore();  // discard the newline left by operator>>

        if (typed != 'y' && typed != 'Y') {
            keepTyping = false;
        }
    }
}

void analyzer(const std::string& line, int& numberOfWords, int& numberOfLines,
              int& spaces, std::string& longestWord, int& numberOfDigits) {

    // Initialize counters
    numberOfWords = 0;
    numberOfLines = 0;
    spaces = 0;
    numberOfDigits = 0;
    longestWord = "";

    bool inWord = false;
    std::string currentWord;

    for (char c : line) {
        // Count lines
        if (c == '\n') {
            ++numberOfLines;
            // End of a word if we were inside one
            if (inWord) {
                if (currentWord.length() > longestWord.length())
                    longestWord = currentWord;
                ++numberOfWords;
                currentWord.clear();
                inWord = false;
            }
            continue;
        }

        if (c == ' ') {
            ++spaces;
            if (inWord) {
                if (currentWord.length() > longestWord.length())
                    longestWord = currentWord;
                ++numberOfWords;
                currentWord.clear();
                inWord = false;
            }
            continue;
        }

        if (std::isdigit(static_cast<unsigned char>(c))) {
            ++numberOfDigits;
        }

        if (!std::isspace(static_cast<unsigned char>(c))) {
            currentWord += c;
            inWord = true;
        }
    }

    if (inWord) {
        if (currentWord.length() > longestWord.length())
            longestWord = currentWord;
        ++numberOfWords;
    }
}