#include <iostream>
#include <windows.h>
#include <cmath>
#include "ModulesParashchenko.h" // підключаємо заголовочний файл з функціями

using namespace std;

int main() {
SetConsoleOutputCP(1251);
SetConsoleCP(1251);

double x, z, S;
char a, b;

// введення значень змінних x, z, a та b
cout << "Введіть значення x: ";
cin >> x;

cout << "Введіть значення z: ";
cin >> z;

cout << "Введіть символ a: ";
cin >> a;

cout << "Введіть символ b: ";
cin >> b;

// викликаємо функції для виконання підзадач та виводимо результат у вихідний потік
cout << "Розробник програми: " << author_name() << " ©" << endl;
cout << "Результат виразу a+1>|b-2|: " << boolalpha << expression_result(a, b) << endl;
cout << "Значення x: " << x << " (0x" << hex << (int)x << ")" << endl;
cout << "Значення z: " << z << " (0x" << hex << (int)z << ")" << endl;
S = s_calculation(x, z);
cout << "Значення виразу S: " << S << endl;

return 0;
}
