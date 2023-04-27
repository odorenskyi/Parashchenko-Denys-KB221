#ifndef S_CALCULATION_H_INCLUDED
#define S_CALCULATION_H_INCLUDED
#include <cmath>

double s_calculation(double x, double z) {
    // ��������, �� x ����� ��� ������� 3
    if (x <= 3) {
        return 0; // ��������� 0, ���� x ����� �� 3
    }

    // ��������� ����������
    double S = pow(3 * sin(sqrt((12 * pow(x, 2)) / log10(x - 3))), 2) + (0.5 * z);
    return S;
}
#endif // S_CALCULATION_H_INCLUDED
