#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream inputFile("your_file.txt");

    if (!inputFile) {
        std::cerr << "Не вдалося відкрити файл." << std::endl;
        return 1;
    }

    std::vector<std::string> lines;

    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    std::cout << "Вміст файлу у зворотньому порядку:" << std::endl;

    for (int i = lines.size() - 1; i >= 0; --i) {
        std::cout << lines[i] << std::endl;
    }

    return 0;
}
