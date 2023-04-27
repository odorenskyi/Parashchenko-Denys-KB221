#ifndef S_CALCULATION_H_INCLUDED
#define S_CALCULATION_H_INCLUDED
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
double s_calculation(double x = 100, double z = 20) {
double S = pow(3 * sin(sqrt((12 * pow(x, 2)) / log10(x - 3))), 2) + (0.5 * z);
cout << "Значення виразу S: " << S << endl;
return S;
}
#endif // S_CALCULATION_H_INCLUDED
