#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle 
{
    private:
        double width;
        double length;
        double height;
    public:   

        Rectangle();
        Rectangle(double, double, double);
        void setWidth(double);
        void setLength(double);
        void setHeight(double);

        double getWidth() const     { return width; }
        double getLength() const    { return length; }
        double getVolume() const    { return width * length * height; }
}; 
#endif