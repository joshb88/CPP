#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Point
{
    private:
        double x_coord, y_coord;
    public:
        Point() : x_coord(0), y_coord(0) {};
        Point(double x, double y) { x_coord = x; y_coord = y; }

        double getXcoord() { return x_coord; }
        double getYcoord() { return y_coord; }

        double findDistance(Point p2)
        {
            return sqrt(pow((p2.getXcoord() - x_coord), 2) + pow((p2.getYcoord() - y_coord), 2));
        }
};

int main()
{
    Point origin;
    Point mypoint(10, 30.5);

    cout << origin.findDistance(mypoint) << endl;

}