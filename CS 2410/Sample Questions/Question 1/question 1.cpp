/*
Write a template function to return maximum parameter type of two (regardless of type). 
Write a test program to validate your code
*/

#include <iostream>
#include <string>

template <typename T> T maximum(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << maximum('j','g') << std::endl;
    std::cout << maximum(15,6) << std::endl;
    std::cout << maximum("hello","world") << std::endl;
}