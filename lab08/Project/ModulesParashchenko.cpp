#include "ModulesParashchenko.h"  // ϳ�������� ������������ ���� � ���������.
#include <cmath> //������ ������������ ���� ��� ������ � ������������� ���������

std::string author_name() {
return "��������� �����";
}
// ������� ��� ���������� ���������� ������ a+1>|b-2|.
bool expression_result(int a,int b) {
return (a + 1) > abs(b - 2);
}
