#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("your_file.txt");

    if (!inputFile) {
        std::cerr << "Не вдалося відкрити файл." << std::endl;
        return 1;
    }

    std::cout << "Вміст файлу у зворотньому порядку:" << std::endl;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::reverse(line.begin(), line.end());
        std::cout << line << std::endl;
    }

    inputFile.close();

    return 0;
}
