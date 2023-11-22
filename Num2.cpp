#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("f.txt");

    if (!inputFile) {
        std::cerr << "Не вдалося відкрити файл." << std::endl;
        return 1;
    }

    std::string longestWordWithE;
    std::string word;

    while (inputFile >> word) {
        if (word.length() > 1 && word[1] == 'е') {
            longestWordWithE = word;
        }
    }

    inputFile.close();

    if (!longestWordWithE.empty()) {
        std::cout << "Найдовше слово серед слів з другою буквою 'е': " << longestWordWithE << std::endl;
    } else {
        std::cout << "Слів з другою буквою 'е' не знайдено." << std::endl;
    }

    return 0;
}
