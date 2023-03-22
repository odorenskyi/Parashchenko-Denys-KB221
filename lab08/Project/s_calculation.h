#ifndef S_CALCULATION_H_INCLUDED
#define S_CALCULATION_H_INCLUDED

double s_calculation(double x, double z) {
    // виконання розрахунків
double S = pow(3 * sin(sqrt((12 * pow(x, 2)) / log10(x - 3))), 2) + (0.5 * z);
return S;
}

#endif // S_CALCULATION_H_INCLUDED
