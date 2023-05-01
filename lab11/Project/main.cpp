#include <iostream>
#include <fstream>
#include <map>
#include <windows.h>

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
        cout << "�� ������� �������� ������� � ����" << endl;
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
        cout << "�� ������� ����������� ������� �� �����" << endl;
    }
}

void addRecord(map<string, string>& dict) {
    string city, code;
    cout << "������ ����� ����: ";
    getline(cin, city);
    cout << "������ ���: ";
    getline(cin, code);
    dict[city] = code;
}

void deleteRecord(map<string, string>& dict) {
    string city;
    cout << "������ ����� ���� ��� ���������: ";
    getline(cin, city);
    auto it = dict.find(city);
    if (it != dict.end()) {
        dict.erase(it);
        cout << "����� ��������" << endl;
    } else {
        cout << "����� �� ��������" << endl;
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
    cout << "������� ������� �� �������� ���������� ����" << endl;
    while (true) {
        cout << "������� ������:" << endl;
        cout << "1. ������ �����" << endl;
        cout << "2. �������� �����" << endl;
        cout << "3. ������� �������" << endl;
        cout << "4. �������� �� �����" << endl;
        int choice;
        cin >> choice;
        cin.ignore(); // ���������� ������ ������ �����
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
                cout << "������� ���������. �����..." << endl;
                return 0;
            default:
                cout << "������� ����" << endl;
        }
    }
}
