#include <iostream>
#include <string>
#include "Functions.h"



int main() 
{
    int arr[] = {1,0,-4,2,6};
    std::cout << "The sum of positive even numbers in the array is: " << recursiveSumPositiveEven(arr, 5) << std::endl;
    

    std::string  str = "Abc12.0K";
    std::cout << "The number of digits in the string is: " << countDigits(str, str.length()) << std::endl;
    return 0;
}