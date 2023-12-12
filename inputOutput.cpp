#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputFileName = "input.txt";
    ifstream inputFile(inputFileName);

    string outputFileName = "output.txt";
    ofstream outputFile(outputFileName);

    if (inputFile.is_open() && outputFile.is_open()) {
        string str;
        // Считывание из файла и запись в другой файл
        while (getline(inputFile, str)) {
            cout << str << '\n';
            // запис строк в файл
            outputFile << str << '\n';
        }

        // Закрытие файлов после использования
        inputFile.close();
        outputFile.close();

        cout << "Данные успешно скопированы из " << inputFileName << " в " << outputFileName << endl;
    }
    else {
        cerr << "Open error." << endl;
        return 1;
    }

    return 0;
}
