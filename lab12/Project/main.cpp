#include <iostream>

using namespace std;

class classlab12_Parashencko {
    private:
        float radius;
        float area;

    public:
        classlab12_Parashencko(float r) {
            radius = r;
            area = 3.14159 * r * r;
        }

        float getRadius() {
            return radius;
        }

        float getArea() {
            return area;
        }

        void setRadius(float r) {
            radius = r;
            area = 3.14159 * r * r;
        }
};

int main() {
    classlab12_Parashencko circle(5);

    cout << "Initial values:" << endl;
    cout << "Radius: " << circle.getRadius() << endl;
    cout << "Area: " << circle.getArea() << endl;

    circle.setRadius(7);

    cout << "New values:" << endl;
    cout << "Radius: " << circle.getRadius() << endl;
    cout << "Area: " << circle.getArea() << endl;

    return 0;
}
