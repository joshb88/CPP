#ifndef SQUARE
#define SQUARE


struct Point { int x, y; Point(); Point(int setx,int sety) : x(setx), y(sety){} };

class Square
{

    private:
        double side_length;
        Point bottom_left;

    public:
        Square();
        Square(double SL, int x, int y);

        double getSideLength()  const                        { return side_length; }
        int getBottomLeftX()    const                        { return bottom_left.x; }
        int getBottomLeftY()    const                        { return bottom_left.y; }
        double getArea()        const                        { return side_length * side_length; }
        double getPerimeter()   const                        { return side_length * 4; }
                
        void setSideLength(double sidelength);
        void setBottomLeftX(int X);       
        void setBottomLeftY(int Y);
        
        bool contains(Point);
        bool intersects(Square);
        void display();
};

#endif