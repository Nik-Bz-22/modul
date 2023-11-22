#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("your_file.txt");

    if (!inputFile) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }

    double number;
    double sumOfPositives = 0;

    while (inputFile >> number) {
        if (number > 0) {
            sumOfPositives += number;
        }
    }

    inputFile.close();

    std::cout << "Сума всіх додатніх чисел у файлі: " << sumOfPositives << std::endl;

    return 0;
}
