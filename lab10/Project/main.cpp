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
    // ³�������� ������� ����
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "�� ������� ������� ������� ����" << endl;
        return 1;
    }

    // ������� ����� � �������� �����
    string inputText;
    getline(inputFile, inputText, '\0');

    // ���������, �� ��� ���� �������� �����
    bool isUkrainian = false;
for (char c : inputText) {
    if ((c >= 0x0400 && c <= 0x04FF) || (c >= 0x0500 && c <= 0x052F) || (c == 0x0456) || (c == 0x0491) || (c == 0x0490) || (c == 0x0407) || (c == 0x0406)) {
        isUkrainian = true;
        break;
    }
}

    // ��������� ������� ����
    inputFile.close();

    // ³�������� �������� ����
    ofstream outputFile("output.txt", ios::out | ios::binary);
    if (!outputFile) {
        cerr << "�� ������� ������� �������� ����" << endl;
        return 1;
    }
// ������ ������ ������� ����� UTF-8 �� ��������� �����
outputFile << char(0xEF) << char(0xBB) << char(0xBF);

// ϳ��������� ������� ��� �� ������ � �����
int numCommas = 0;
int numPeriods = 0;
for (char c : inputText) {
if (c == ',') {
numCommas++;
} else if (c == '.') {
numPeriods++;
}
}
// �������� ������� ��� �� ������ � �������
cout << "ʳ������ ���: " << numCommas << endl;
cout << "ʳ������ ������: " << numPeriods << endl;

// �������� ������� ��� �� ������ � �������� ����
outputFile << "ʳ������ ���: " << numCommas << endl;
outputFile << "ʳ������ ������: " << numPeriods << endl;

// �������� ���� �� ��� �������� � �������
time_t currentTime = time(nullptr);
tm* localTime = localtime(&currentTime);
cout << "���� �� ��� ��������: " << asctime(localTime) << endl;

// �������� ���� �� ��� �������� � �������� ����
outputFile << "���� �� ��� ��������: " << asctime(localTime) << endl;

    // ������� ������� ������� � �����
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

    // �������� ������� ����� � �������
    for (const string& paragraph : paragraphs) {
        cout << paragraph << endl << endl;
    }

    // �������� ������� ����� � �������� ����
    for (const string& paragraph : paragraphs) {
        outputFile << paragraph << endl << endl;
    }

    // �������� ���������� ��� ���� ������ � �������� ����
    if (isUkrainian) {
        outputFile << "���� ������: ���������\n";
} else {
outputFile << "���� ������: ����\n";
}

// �������� ��
time_t now = time(0);
tm* ltm = localtime(&now);
int year = 1900 + ltm->tm_year;
cout << "г� ��������:  " << year << endl;

// ������� ����� ���
    double x = 2, z = 50;
    int b;
    inputFile >> x >> z >> b;

    // ���������� ��������� ��������� ������� s_calculation � ����������� x, z
    double result = s_calculation(x, z);

    // �������� ��������� ������� ������� � �������� ����
    outputFile << "��������� ��������� ������� s_calculation � ����������� x = " << x << ", z = " << z << " ������� " << result << endl;

    // ���������� ����� b � �������� ������ �� �������� ���� � �������� ����
    string binary = bitset<32>(b).to_string();
    outputFile << "����� " << b << " � ������� ����: " << binary << endl;


// ��������� �������� ����
outputFile.close();

return 0;
}
