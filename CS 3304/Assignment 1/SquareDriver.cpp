#include <iostream>
#include <iomanip>
#include "Square.h"

using namespace std;

int main()
{

    Square a = Square();
    Square b = Square(3,-2,4);
    Square c = Square(2,2,1);
    Square d = Square(-3,5,8);
    Point p1 = {2,2};
    a.display();
    b.display();
    c.display();
    d.display();
    cout << a.getSideLength() << endl;
    cout << b.getBottomLeftX() << endl;
    cout << c.getBottomLeftY() << endl;
    c.setSideLength(-7);
    d.setSideLength(10);
    d.setBottomLeftX(-10);
    d.setBottomLeftY(-10);
    c.display();
    d.display();
    cout << a.getArea() << endl;
    cout << b.getPerimeter() << endl;
    if (a.contains(p1)) {
    cout << "Square a contains p1" << endl;
    }
    if (!b.contains(p1)) {
    cout << "Square b does not contain p1" << endl;
    }
    if (a.intersects(b)) {
    cout << " Square a intersects with Square b" << endl;
    }
    if (!b.intersects(c)) {
    cout << " Square b does not intersect with Square c" << endl;
    }
    if (d.intersects(a)) {
    cout << " Square d intersects with Square a" << endl;
    }
};