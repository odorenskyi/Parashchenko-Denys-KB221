#include <Windows.h>
#include <iostream>
using namespace std;

int task_9_1() {

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

int task_9_2() {
    double size_cm;
    cout << "Введіть розмір взуття в сантиметрах: ";
    cin >> size_cm;

    double size_ua = (size_cm / 0.44) - 0.5;
    double size_uk = (size_cm / 0.635) - 1;

    cout << "Розмір взуття в Україні: " << size_ua << endl;
    cout << "Розмір взуття у Великобританії: " << size_uk << endl;

    return 0;
}

int task_9_3() {
    unsigned int N;
    cout << "Введіть натуральне число від 0 до 21359010: ";
    cin >> N;

    int count = 0;

    if ((N >> 11) & 1) {
        while (N) {
            count += N & 1 ? 0 : 1;
            N >>= 1;
        }
    } else {
        while (N) {
            count += N & 1 ? 1 : 0;
            N >>= 1;
        }
    }

    cout << "Кількість " << (count ? "одиниць" : "нулів") << ": " << count << endl;

    return 0;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    char choice;

    do {
        cout << "Оберіть завдання: (u - 9.1, t - 9.2, r - 9.3): ";
        cin >> choice;

    try {
        switch (choice) {
            case 'u':
                task_9_1();
                break;
            case 't':
                task_9_2();
                break;
            case 'r':
                task_9_3();
                break;
            case 'w':
            case 'i':
                return 0;
            default:
                throw invalid_argument("Неправильний ввід.");
        }
    } catch (const exception& e) {
        cout << e.what() << endl;
        Beep(1000, 500);
    }

    cout << "Продовжити? (y/n): ";
    cin >> choice;

} while (choice == 'y');
}
