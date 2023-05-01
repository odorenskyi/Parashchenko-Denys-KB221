#include <iostream>
#include <fstream>
#include <map>
#include <windows.h>
#include "struct_type_project_2.h"

using namespace std;

void saveDictionary(const map<string, string>& dict, const string & fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (auto const& pair : dict) {
    string key = pair.first;
    string value = pair.second;
            file << key << "," << value << endl;
        }
        file.close();
    } else {
        cout << "Не вдалося зберегти словник у файл" << endl;
    }
}

void loadDictionary(map<string, string>& dict, const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(",");
            if (pos != string::npos) {
                string city = line.substr(0, pos);
                string code = line.substr(pos + 1);
                dict[city] = code;
            }
        }
        file.close();
    } else {
        cout << "Не вдалося завантажити словник із файлу" << endl;
    }
}

void addRecord(map<string, string>& dict) {
    string city, code;
    cout << "Введіть назву міста: ";
    getline(cin, city);
    cout << "Введіть код: ";
    getline(cin, code);
    dict[city] = code;
}

void deleteRecord(map<string, string>& dict) {
    string city;
    cout << "Введіть назву міста для видалення: ";
    getline(cin, city);
    auto it = dict.find(city);
    if (it != dict.end()) {
        dict.erase(it);
        cout << "Запис видалено" << endl;
    } else {
        cout << "Запис не знайдено" << endl;
    }
}

void printDictionary(const map<string, string>& dict) {
    for (auto const& pair : dict) {
        string key = pair.first;
        string value = pair.second;
        cout << key << ": " << value << endl;
    }
}


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    map<string, string> dict;
    loadDictionary(dict, "dictionary.txt");
    cout << "Ласкаво просимо до словника телефонних кодів" << endl;
    while (true) {
        cout << "Виберіть варіант:" << endl;
        cout << "1. Додати запис" << endl;
        cout << "2. Видалити запис" << endl;
        cout << "3. Вивести словник" << endl;
        cout << "4. Зберегти та вийти" << endl;
        int choice;
        cin >> choice;
        cin.ignore(); // ігнорувати символ нового рядка
        switch (choice) {
            case 1:
                addRecord(dict);
                break;
            case 2:
                deleteRecord(dict);
                break;
            case 3:
                printDictionary(dict);
                break;
            case 4:
                saveDictionary(dict, "dictionary.txt");
                cout << "Словник збережено. Вихід..." << endl;
                return 0;
            default:
                cout << "Невірний вибір" << endl;
        }
    }
}
