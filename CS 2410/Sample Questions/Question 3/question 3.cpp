/*
Rewrite the linear search you learned to use generic type for array elements.
Test the function with array of int,double, string.
*/

#include <iostream>
#include <string>

template <typename T> 
int linearsearch(T array[], T target, int arraySize)
{
    // Going through array sequentially
    for (int i = 0; i < arraySize; i++)
        if (array[i] == target)
            return i;
    return -1;
}

int main()
{

	int intArray[] = { 6 , 43 ,23 ,6, 12 ,43, 3, 4, 2, 6 };
	int n, int_target;
    int_target = 12;
	n = sizeof(intArray) / sizeof(int); // size of arr
    std::cout << linearsearch(intArray, int_target, n) << std::endl;


    std::string arraystring[] = {"hello", "world", "from", "josh"};
    n = sizeof(arraystring) / sizeof(std::string);
    std::string string_target = "josh";
    std::cout << linearsearch(arraystring, string_target, n) << std::endl;
}

