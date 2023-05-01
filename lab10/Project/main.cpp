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
    //SetConsoleOutputCP(1251);
   // SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    // Â³äêðèâàºìî âõ³äíèé ôàéë
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Íå âäàëîñÿ â³äêðèòè âõ³äíèé ôàéë" << endl;
        return 1;
    }

    // Ç÷èòóºìî òåêñò ç âõ³äíîãî ôàéëó
    string inputText;
    getline(inputFile, inputText, '\0');

    // Âèçíà÷àºìî, äî ÿêî¿ ìîâè íàëåæèòü òåêñò
    bool isUkrainian = false;
for (char c : inputText) {
    if ((c >= 0x0400 && c <= 0x04FF) || (c >= 0x0500 && c <= 0x052F) || (c == 0x0456) || (c == 0x0491) || (c == 0x0490) || (c == 0x0407) || (c == 0x0406)) {
        isUkrainian = true;
        break;
    }
}

    // Çàêðèâàºìî âõ³äíèé ôàéë
    inputFile.close();

    // Â³äêðèâàºìî âèõ³äíèé ôàéë
    ofstream outputFile("output.txt", ios::out | ios::binary);
    if (!outputFile) {
        cerr << "Íå âäàëîñÿ â³äêðèòè âèõ³äíèé ôàéë" << endl;
        return 1;
    }
// Äîäàºìî ìàðêåð ïîðÿäêó áàéò³â UTF-8 äî âèõ³äíîãî ôàéëó
outputFile << char(0xEF) << char(0xBB) << char(0xBF);

// Ï³äðàõîâóºìî ê³ëüê³ñòü êîì òà êðàïîê ó òåêñò³
int numCommas = 0;
int numPeriods = 0;
for (char c : inputText) {
if (c == ',') {
numCommas++;
} else if (c == '.') {
numPeriods++;
}
}
// Âèâîäèìî ê³ëüê³ñòü êîì òà êðàïîê ó êîíñîëü
cout << "Ê³ëüê³ñòü êîì: " << numCommas << endl;
cout << "Ê³ëüê³ñòü êðàïîê: " << numPeriods << endl;

// Çàïèñóºìî ê³ëüê³ñòü êîì òà êðàïîê ó âèõ³äíèé ôàéë
outputFile << "Ê³ëüê³ñòü êîì: " << numCommas << endl;
outputFile << "Ê³ëüê³ñòü êðàïîê: " << numPeriods << endl;

// Âèâîäèìî äàòó òà ÷àñ äîçàïèñó ó êîíñîëü
time_t currentTime = time(nullptr);
tm* localTime = localtime(&currentTime);
cout << "Äàòà òà ÷àñ äîçàïèñó: " << asctime(localTime) << endl;

// Çàïèñóºìî äàòó òà ÷àñ äîçàïèñó ó âèõ³äíèé ôàéë
outputFile << "Äàòà òà ÷àñ äîçàïèñó: " << asctime(localTime) << endl;

    // Çì³íþºìî ïîðÿäîê àáçàö³â ó òåêñò³
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

    // Âèâîäèìî çì³íåíèé òåêñò ó êîíñîëü
    for (const string& paragraph : paragraphs) {
        cout << paragraph << endl << endl;
    }

    // Çàïèñóºìî çì³íåíèé òåêñò ó âèõ³äíèé ôàéë
    for (const string& paragraph : paragraphs) {
        outputFile << paragraph << endl << endl;
    }

    // Çàïèñóºìî ³íôîðìàö³þ ïðî ìîâó òåêñòó ó âèõ³äíèé ôàéë
    if (isUkrainian) {
        outputFile << "Ìîâà òåêñòó: Óêðà¿íñüêà\n";
} else {
outputFile << "Ìîâà òåêñòó: ²íøà\n";
}

// Âèâîäèìî ð³ê
time_t now = time(0);
tm* ltm = localtime(&now);
int year = 1900 + ltm->tm_year;
cout << "Ð³ê ðîçðîáêè:  " << year << endl;

// Ç÷èòóºìî âõ³äí³ äàí³
    double x = 2, z = 50;
    int b;
    inputFile >> x >> z >> b;

    // Îá÷èñëþºìî ðåçóëüòàò âèêîíàííÿ ôóíêö³¿ s_calculation ç àðãóìåíòàìè x, z
    double result = s_calculation(x, z);

    // Çàïèñóºìî ðåçóëüòàò âèõ³äíî¿ ôóíêö³¿ ó âèõ³äíèé ôàéë
    outputFile << "Ðåçóëüòàò âèêîíàííÿ ôóíêö³¿ s_calculation ç àðãóìåíòàìè x = " << x << ", z = " << z << " äîð³âíþº " << result << endl;

    // Êîíâåðòóºìî ÷èñëî b â äâ³éêîâèé ôîðìàò òà çàïèñóºìî éîãî ó âèõ³äíèé ôàéë
    string binary = bitset<32>(b).to_string();
    outputFile << "×èñëî " << b << " ó äâ³éêîâ³é ôîðì³: " << binary << endl;


// Çàêðèâàºìî âèõ³äíèé ôàéë
outputFile.close();

return 0;
}
