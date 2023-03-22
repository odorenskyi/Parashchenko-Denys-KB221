#include "ModulesParashchenko.h"  // Підключаємо заголовочний файл з функціями.
#include <cmath> //Включає заголовочний файл для роботи з математичними функціями

std::string author_name() {
return "Паращенко Денис";
}
// Функція для обчислення результату виразу a+1>|b-2|.
bool expression_result(int a,int b) {
return (a + 1) > abs(b - 2);
}
