#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    std::ofstream outputFile("output_file.txt");

    if (!outputFile) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return 1;
    }

    double eps;
    std::cout << "Введіть eps: ";
    std::cin >> eps;

    int count = 0;

    for (int i = 1; ; ++i) {
        double Xi = (i - 0.1) / (std::pow(i, 3) + std::fabs(std::tan(2 * i)));

        if (Xi > eps) {
            outputFile << Xi << std::endl;
            ++count;
        } else {
            break;  // Зупинити цикл, якщо елемент менший або рівний eps
        }
    }

    outputFile.close();

    std::cout << "Кількість елементів у файлі: " << count << std::endl;

    // Виведення вмісту файлу на екран
    std::ifstream inputFile("output_file.txt");

    if (!inputFile) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return 1;
    }

    std::cout << "Вміст файлу:" << std::endl;

    double element;
    while (inputFile >> element) {
        std::cout << element << std::endl;
    }

    inputFile.close();

    return 0;
}
