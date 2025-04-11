#include <iostream>
using namespace std;

// ======= КЛАСС Point =======
class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {
        cout << "[Point] Конструктор без параметров" << endl;
    }
    
    Point(int x, int y) : x(x), y(y) {
        cout << "[Point] Конструктор с параметрами" << endl;
    }

    Point(const Point& other) : x(other.x), y(other.y) {
        cout << "[Point] Конструктор копирования" << endl;
    }

    virtual ~Point() {
        cout << "[Point] Виртуальный деструктор" << endl;
    }

    void show() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

// ======= КЛАСС Circle (наследует Point) =======
class Circle : public Point {
private:
    int radius;

public:
    Circle() : Point(), radius(1) {
        cout << "[Circle] Конструктор без параметров" << endl;
    }

    Circle(int x, int y, int r) : Point(x, y), radius(r) {
        cout << "[Circle] Конструктор с параметрами" << endl;
    }

    Circle(const Circle& other) : Point(other), radius(other.radius) {
        cout << "[Circle] Конструктор копирования" << endl;
    }

    ~Circle() override {
        cout << "[Circle] Деструктор" << endl;
    }

    void show() {
        cout << "Circle с радиусом " << radius << " и центром: ";
        Point::show();
    }
};

// ======= КЛАСС Rectangle (композиция объектов) =======
class Rectangle {
private:
    Point topLeft;
    Point bottomRight;

public:
    Rectangle() : topLeft(0, 0), bottomRight(1, 1) {
        cout << "[Rectangle] Конструктор" << endl;
    }

    ~Rectangle() {
        cout << "[Rectangle] Деструктор" << endl;
    }

    void show() {
        cout << "Rectangle от ";
        topLeft.show();
        cout << " до ";
        bottomRight.show();
    }
};

// ======= КЛАСС Triangle (композиция через указатели) =======
class Triangle {
private:
    Point* p1;
    Point* p2;
    Point* p3;

public:
    Triangle() {
        cout << "[Triangle] Конструктор" << endl;
        p1 = new Point(0, 0);
        p2 = new Point(1, 0);
        p3 = new Point(0, 1);
    }

    ~Triangle() {
        cout << "[Triangle] Деструктор" << endl;
        delete p1;
        delete p2;
        delete p3;
    }

    void show() {
        cout << "Triangle:" << endl;
        p1->show();
        p2->show();
        p3->show();
    }
};



int main() {
    cout << "--- Статический объект Point ---" << endl;
    Point p1;
    p1.show();

    cout << "--- Объект Point с параметрами ---" << endl;
    Point p2(10, 20);
    p2.show();

    cout << "--- Копирование Point ---" << endl;
    Point p3 = p2;
    p3.show();

    cout << "--- Динамический Point ---" << endl;
    Point* p4 = new Point(5, 7);
    p4->show();
    delete p4;

    cout << "\n--- Наследование: Circle ---" << endl;
    Circle c1(1, 2, 5);
    c1.show();

    cout << "--- Указатель на базовый класс → Circle ---" << endl;
    Point* base = new Circle(3, 4, 6);
    delete base; // вызов виртуального деструктора

    cout << "\n--- Композиция: Rectangle ---" << endl;
    Rectangle rect;
    rect.show();

    cout << "\n--- Композиция (указатели): Triangle ---" << endl;
    Triangle tri;
    tri.show();

    cout << "\n--- Конец main() ---" << endl;
    cout << "\n--- Конец main() ---" << endl;
    return 0;
}
