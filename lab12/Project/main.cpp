#include <iostream>
#include <stdexcept>
#include <Windows.h>

class ClassLab12_Parashencko {
private:
  double radius;  // Радіус кола

public:
  // Конструктор класу
  ClassLab12_Parashencko(double r) {
    // Валідація вхідних даних
    if (r < 0) {
      throw std::invalid_argument("Радіус має бути додатнім числом");
    }
    radius = r;
  }

  // Функція для зміни значення радіуса
  void setRadius(double r) {
    // Валідація вхідних даних
    if (r < 0) {
      throw std::invalid_argument("Радіус має бути додатнім числом");
    }
    radius = r;
  }

  // Функція для отримання значення радіуса
  double getRadius() const {
    return radius;
  }

  // Функція для обчислення площі кола
  double getArea() const {
    return 3.14159 * radius * radius;
  }
};



int main() {
SetConsoleOutputCP(1251);
SetConsoleCP(1251);
//SetConsoleOutputCP(CP_UTF8);
  double radius;

  std::cout << "Введіть радіус кола: ";
  std::cin >> radius;

  try {
    // Створення об'єкта класу ClassLab12_Parashencko
    ClassLab12_Parashencko circle(radius);

    // Отримання значення радіуса та площі кола
    std::cout << "Радіус кола: " << circle.getRadius() << std::endl;
    std::cout << "Площа кола: " << circle.getArea() << std::endl;

    // Зміна значення радіуса та повторне обчислення площі кола
    double newRadius;
    std::cout << "Введіть нове значення радіуса: ";
    std::cin >> newRadius;
    circle.setRadius(newRadius);
    std::cout << "Новий радіус кола: " << circle.getRadius() << std::endl;
    std::cout << "Нова площа кола: " << circle.getArea() << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << "Помилка: " << e.what() << std::endl;
  }

  return 0;
}
