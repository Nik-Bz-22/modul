#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& word) {
    std::string reversed = word;
    std::reverse(reversed.begin(), reversed.end());
    return word == reversed;
}

int main() {
    std::ifstream inputFile("ваш_файл.txt");
    
    if (!inputFile) {
        std::cerr << "Не удается открыть файл." << std::endl;
        return 1;
    }

    std::string word;

    while (inputFile >> word) {
        if (isPalindrome(word)) {
            std::cout << word << std::endl;
        }
    }

    inputFile.close();
    return 0;
}
