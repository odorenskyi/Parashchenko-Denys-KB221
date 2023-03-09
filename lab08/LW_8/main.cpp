#include <iostream>
#include <windows.h>
#include <cmath>
#include "ModulesParashchenko.h" // ��������� ������������ ���� � ���������

using namespace std;

int main() {
SetConsoleOutputCP(1251);
SetConsoleCP(1251);

double x, z, S;
char a, b;

// �������� ������� ������ x, z, a �� b
cout << "������ �������� x: ";
cin >> x;

cout << "������ �������� z: ";
cin >> z;

cout << "������ ������ a: ";
cin >> a;

cout << "������ ������ b: ";
cin >> b;

// ��������� ������� ��� ��������� ������� �� �������� ��������� � �������� ����
cout << "��������� ��������: " << author_name() << " �" << endl;
cout << "��������� ������ a+1>|b-2|: " << boolalpha << expression_result(a, b) << endl;
cout << "�������� x: " << x << " (0x" << hex << (int)x << ")" << endl;
cout << "�������� z: " << z << " (0x" << hex << (int)z << ")" << endl;
S = s_calculation(x, z);
cout << "�������� ������ S: " << S << endl;

return 0;
}
