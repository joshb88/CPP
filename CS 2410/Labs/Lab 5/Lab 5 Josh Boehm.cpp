/*
Josh Boehm
4 October 2022
CS 2410
Lab 5

Part 1.
Write a program to demonstrate class called Room.   and one object  
Room1, This program has 3 private members L (lenght), W (width), and H (hight), find volume of this room 
Assigned values to the member of this class at the main.  Display volume to the screen.

Part 2
Use previous program to demonstrate member access specifier (public, and private).

Part 3.
Use previous program and defind your member funcion outside of the class.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include "Rectangle.h"

using namespace std;

int main()
{
    Rectangle Room1(10,20,10);
    cout << "The length is " << Room1.getLength() << "." << endl;
    Room1.setLength(10);
    cout << "The new length is " << Room1.getLength() << "." << endl;
    cout << "The volume of the room is " << Room1.getVolume() << "." << endl;
}
