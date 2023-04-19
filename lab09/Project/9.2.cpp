#include <iostream>
using namespace std;

int task_9_2() {
    double size_cm;
    cout << "Enter shoe size in centimeters: ";
    cin >> size_cm;

    double size_ua = (size_cm / 0.44) - 0.5;
    double size_uk = (size_cm / 0.635) - 1;

    cout << "Shoe size in Ukraine: " << size_ua << endl;
    cout << "Shoe size in UK: " << size_uk << endl;

    return 0;
}
