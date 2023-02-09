#include <iostream>
#include <cstdlib>
#include "Square.h"

Square::Square() : side_length(5), bottom_left(0,0){}
Square::Square(double SL, int x, int y)
{
    if (SL > 0)
    {side_length = SL;}
    else
    { 
        std::cout << "Cannot have a side length less than or equal to zero; setting to 10." << std::endl;
        side_length = 10;
    }
    Point bottom_left = {x, y};
}
        
void Square::setSideLength(double sidelength)         
{
    if (sidelength > 0) 
        side_length = sidelength;
    else 
    {
        std::cout << "Invalid length; Must be greater than 0.\n";
        exit(EXIT_FAILURE);
    }
}
void Square::setBottomLeftX(int X)                  { bottom_left.x = X; }
void Square::setBottomLeftY(int Y)                  { bottom_left.y = Y; }

bool Square::contains(Point given_point)
{
    if (((given_point.x >= bottom_left.x) && (given_point.x <= (bottom_left.x + side_length))) &&  // Checks if the the x-value of the point is within the bounds of the sqaure's range
        ((given_point.y >= bottom_left.y) && (given_point.y <= (bottom_left.y + side_length))))    // Checks if the the y-value of the point is within the bounds of the sqaure's range
    { return true; }
    else
    { return false; }
}
bool Square::intersects(Square s)
{
    if (Square::bottom_left.x + side_length < s.bottom_left.x ||
        s.bottom_left.x + side_length < bottom_left.x ||
        bottom_left.y + side_length < s.bottom_left.y ||
        s.bottom_left.y + side_length < bottom_left.y)
    { return false; }
    else 
    { return true; }
}

void Square::display()
{
    std::cout << "side length: " << getSideLength() << ", bottom-left point: (" << getBottomLeftX() << "," << getBottomLeftY() << ")" << std::endl;
}
