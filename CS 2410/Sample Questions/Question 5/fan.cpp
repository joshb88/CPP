#include <iostream>
#include <string>

using namespace std;

class Fan
{
    private:
        int speed;
        bool on;
        double radius;
    public:
        Fan() { speed = 1; on = false; radius = 5; }
        Fan(int news, double newr) { speed = news; on = false; radius = newr; }

        void setSpeed(int s) { speed = s; } 
        void setOn(bool o) { on = o; }
        void setRadius(double r) { radius = r; } 

        int getSpeed() { return speed; }
        bool getOn() { return on; }
        double getRadius() {return radius; }
};

int main()
{
    Fan testfan1(3, 10);
    Fan testfan2(2, 5);

    cout << "Fan 1 has speed " << testfan1.getSpeed() << " and radius " << testfan1.getRadius() << "." << endl;
    cout << "Fan 1 has speed " << testfan2.getSpeed() << " and radius " << testfan2.getRadius() << "." << endl;
}