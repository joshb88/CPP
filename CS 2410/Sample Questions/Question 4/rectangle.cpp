#include <iostream>
#include <string>

class Rectangle
{
    private:
        double width ,height;
    public:
        Rectangle() { width = height = 1;}
        Rectangle(double w, double h) 
        { 
            width = w;
            height = h;
        }
        void setWidth(double setw) { width = setw; }
        void setLength(double setl) { height = setl; }

        double getWidth()           { return width; }
        double getLength()          { return height; }
        double getArea()            { return width * height; }
        double getPerimeter()       { return 2 * width + 2 * height; }
};

int main() 
{
    Rectangle myRect(4, 40);
    std::cout << "The area of a rectangle with a width " << myRect.getWidth() << std::endl;
}


