#include "Rectangle.h"
#include <iostream>
#include <cstdlib>

using namespace std;


Rectangle::Rectangle()
    : width(0), length(0), height(0)
{
    // Initializing a constructor with 0's if not provided.
}

Rectangle::Rectangle(double w, double len, double h)
{
    width = w;
    length = len;
    height = h;
}


void Rectangle::setWidth(double w)
{
    if (w >= 0)
        width = w; 
    else
    {
        cout << "Invalid width\n"; 
        exit(EXIT_FAILURE);
    } 
}

void Rectangle::setLength(double len) 
{
    if (len >= 0) 
        length = len;
    else 
    {
        cout << "Invalid length\n";
        exit(EXIT_FAILURE);
    }
}

void Rectangle::setHeight(double h) 
{
    if (h >= 0) 
        height = h;
    else 
    {
        cout << "Invalid length\n";
        exit(EXIT_FAILURE);
    }
}