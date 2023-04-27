#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include "s_calculation.h"
#include "ModulesParashchenko.h"
#include <bitset>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    // Відкриваємо вхідний файл
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Не вдалося відкрити вхідний файл" << endl;
        return 1;
    }

    // Зчитуємо текст з вхідного файлу
    string inputText;
    getline(inputFile, inputText, '\0');

    // Визначаємо, до якої мови належить текст
    bool isUkrainian = false;
for (char c : inputText) {
    if ((c >= 0x0400 && c <= 0x04FF) || (c >= 0x0500 && c <= 0x052F) || (c == 0x0456) || (c == 0x0491) || (c == 0x0490) || (c == 0x0407) || (c == 0x0406)) {
        isUkrainian = true;
        break;
    }
}

    // Закриваємо вхідний файл
    inputFile.close();

    // Відкриваємо вихідний файл
    ofstream outputFile("output.txt", ios::out | ios::binary);
    if (!outputFile) {
        cerr << "Не вдалося відкрити вихідний файл" << endl;
        return 1;
    }
// Додаємо маркер порядку байтів UTF-8 до вихідного файлу
outputFile << char(0xEF) << char(0xBB) << char(0xBF);

// Підраховуємо кількість ком та крапок у тексті
int numCommas = 0;
int numPeriods = 0;
for (char c : inputText) {
if (c == ',') {
numCommas++;
} else if (c == '.') {
numPeriods++;
}
}
// Виводимо кількість ком та крапок у консоль
cout << "Кількість ком: " << numCommas << endl;
cout << "Кількість крапок: " << numPeriods << endl;

// Записуємо кількість ком та крапок у вихідний файл
outputFile << "Кількість ком: " << numCommas << endl;
outputFile << "Кількість крапок: " << numPeriods << endl;

// Виводимо дату та час дозапису у консоль
time_t currentTime = time(nullptr);
tm* localTime = localtime(&currentTime);
cout << "Дата та час дозапису: " << asctime(localTime) << endl;

// Записуємо дату та час дозапису у вихідний файл
outputFile << "Дата та час дозапису: " << asctime(localTime) << endl;

    // Змінюємо порядок абзаців у тексті
    vector<string> paragraphs;
    size_t start = 0;
    size_t end = inputText.find("\n\n");
    while (end != string::npos) {
        paragraphs.push_back(inputText.substr(start, end - start));
        start = end + 2;
        end = inputText.find("\n\n", start);
    }
    paragraphs.push_back(inputText.substr(start));
    reverse(paragraphs.begin(), paragraphs.end());

    // Виводимо змінений текст у консоль
    for (const string& paragraph : paragraphs) {
        cout << paragraph << endl << endl;
    }

    // Записуємо змінений текст у вихідний файл
    for (const string& paragraph : paragraphs) {
        outputFile << paragraph << endl << endl;
    }

    // Записуємо інформацію про мову тексту у вихідний файл
    if (isUkrainian) {
        outputFile << "Мова тексту: Українська\n";
} else {
outputFile << "Мова тексту: Інша\n";
}

// Виводимо рік
time_t now = time(0);
tm* ltm = localtime(&now);
int year = 1900 + ltm->tm_year;
cout << "Рік розробки:  " << year << endl;

// Зчитуємо вхідні дані
    double x = 2, z = 50;
    int b;
    inputFile >> x >> z >> b;

    // Обчислюємо результат виконання функції s_calculation з аргументами x, z
    double result = s_calculation(x, z);

    // Записуємо результат вихідної функції у вихідний файл
    outputFile << "Результат виконання функції s_calculation з аргументами x = " << x << ", z = " << z << " дорівнює " << result << endl;

    // Конвертуємо число b в двійковий формат та записуємо його у вихідний файл
    string binary = bitset<32>(b).to_string();
    outputFile << "Число " << b << " у двійковій формі: " << binary << endl;


// Закриваємо вихідний файл
outputFile.close();

return 0;
}
