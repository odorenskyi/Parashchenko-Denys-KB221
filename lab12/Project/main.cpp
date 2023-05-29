#include <iostream>
#include <stdexcept>
#include <Windows.h>

class ClassLab12_Parashencko {
private:
  double radius;  // ����� ����

public:
  // ����������� �����
  ClassLab12_Parashencko(double r) {
    // �������� ������� �����
    if (r < 0) {
      throw std::invalid_argument("����� �� ���� ������� ������");
    }
    radius = r;
  }

  // ������� ��� ���� �������� ������
  void setRadius(double r) {
    // �������� ������� �����
    if (r < 0) {
      throw std::invalid_argument("����� �� ���� ������� ������");
    }
    radius = r;
  }

  // ������� ��� ��������� �������� ������
  double getRadius() const {
    return radius;
  }

  // ������� ��� ���������� ����� ����
  double getArea() const {
    return 3.14159 * radius * radius;
  }
};



int main() {
SetConsoleOutputCP(1251);
SetConsoleCP(1251);
//SetConsoleOutputCP(CP_UTF8);
  double radius;

  std::cout << "������ ����� ����: ";
  std::cin >> radius;

  try {
    // ��������� ��'���� ����� ClassLab12_Parashencko
    ClassLab12_Parashencko circle(radius);

    // ��������� �������� ������ �� ����� ����
    std::cout << "����� ����: " << circle.getRadius() << std::endl;
    std::cout << "����� ����: " << circle.getArea() << std::endl;

    // ���� �������� ������ �� �������� ���������� ����� ����
    double newRadius;
    std::cout << "������ ���� �������� ������: ";
    std::cin >> newRadius;
    circle.setRadius(newRadius);
    std::cout << "����� ����� ����: " << circle.getRadius() << std::endl;
    std::cout << "���� ����� ����: " << circle.getArea() << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << "�������: " << e.what() << std::endl;
  }

  return 0;
}
