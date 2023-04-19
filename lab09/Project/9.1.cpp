#include <iostream>
#include <windows.h>
using namespace std;

int task_9_1() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);

    double volume, cost;

    cout << "Введіть об'єм використаного газу за місяць (м³): ";
    cin >> volume;

    if (volume <= 208) {
        cost = volume * 1.299;
    } else if (volume <= 500) {
        cost = 208 * 1.299 + (volume - 208) * 1.788;
    } else {
        cost = 208 * 1.299 + 292 * 1.788 + (volume - 500) * 3.645;
    }

    cout << "Сума до сплати за спожитий газ: " << cost << " грн" << endl;

    return 0;
}
