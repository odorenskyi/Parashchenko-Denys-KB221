#include "ModulesParashchenko.h"
#include <cmath>

std::string author_name() {
return "Паращенко Денис";
}

bool expression_result(char a, char b) {
return (a + 1) > abs(b - 2);
}

double s_calculation(double x, double z) {
double S = pow(3 * sin(sqrt(12 * pow(x, 2)) / log10(x - 3)), 2) + 0.5 * z;
return S;
}
