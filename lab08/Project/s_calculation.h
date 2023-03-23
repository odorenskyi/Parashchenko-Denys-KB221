#ifndef S_CALCULATION_H_INCLUDED
#define S_CALCULATION_H_INCLUDED
#include <string>
#include <iomanip>

using namespace std; //Директива імпорту простору імен. Ця директива дозволяє використовувати ідентифікатори з простору імен std (стандартна бібліотека С++) без префіксу "std::".
double s_calculation(double x, double z) {
    // виконання розрахунків
double S = pow(3 * sin(sqrt((12 * pow(x, 2)) / log10(x - 3))), 2) + (0.5 * z);
return S;
}
string DecHex(double x, double z) {
    ostringstream oss;
    oss << "Десяткова : " << endl
        << "'x' -> " << dec << x << endl
        << "'z' -> " << dec << z << endl << endl;
    oss << "Шістнадцяткова: " << endl
        << "'x' -> " << hex << (int)x << endl
        << "'z' -> " << hex << (int)z << endl
        << endl;
    return oss.str();
}
#endif // S_CALCULATION_H_INCLUDED
