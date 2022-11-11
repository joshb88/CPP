/*
Design a generic function that returns a maximum element from an array. 
The function should have two parameters. 
One is the array of generic type.
The other is the size of the array.
Test the function with an array of int, double, and string.
*/

#include <iostream>
#include <string>

template <typename T> T largestElement(const T arr[], const int size) 
{
    if (size < 1) throw runtime_error("Array Size Error");

    T largestElement = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (largestElement < arr[i])
            largestElement = arr[i];
    }
    return largestElement;
}


int main()
{

}