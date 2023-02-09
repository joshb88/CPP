#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

/* Question 1 */
void countBetween(int array[], int num_of_elements, int value_a, int value_b);

/* Question 2 */
int* arrange(int array[], int size);

/* Question 3 */
struct Point { int x = 0, y = 0; };
float distance(Point a, Point b) { return sqrt( pow((a.x - b.x),2) + pow((a.y - b.y),2) ); }

/* Driver Code */
int main()
{
    /* Question 1 */
    int question1[] = {3,7,9,15,4,6};
    countBetween(question1, 6, 7, 4);


    /* Question 2*/
    // Part 1
    int question2part1[] = { 3,7,13,12,6,4 };
    int *b = arrange(question2part1, 6);

    // Print the results
    for (int i = 0; i < 6; i++) 
    {
        std::cout << *(b+i) << " ";
    }
    std::cout << std::endl;

    // Part 2
    int question2part2[] = { 19,6,22,11,4,9,15 };
    int *d = arrange(question2part2, 7);

    // Print the results
    for (int j = 0; j < 7; j++) 
    {
        std::cout << *(d+j) << " ";
    }
    std::cout << std::endl;

    /* Question 3 */
    Point first, second;
    first.x = 0, first.y = 0;
    second.x = 3, second.y = 4;
    std::cout << "The distance between the two points is " << distance(first, second) << "." << std::endl;
}

/* Question 1 */
void countBetween(int array[], int num_of_elements, int value_a, int value_b)
{  
    int count = 0;

    if (value_a > value_b)
    {
        for (int i = 0; i < num_of_elements; i++)
        {
            if (array[i] <= value_a && array[i] >= value_b) {count++;}
        }
        if (count == 1)
        {std::cout << "There is " << count << " value between " << value_a << " and " << value_b << std::endl;}
        else
        {std::cout << "There are " << count << " values between " << value_a << " and " << value_b << std::endl;}

    }
    else if(value_a < value_b)
    {
        for (int i = 0; i < num_of_elements; i++)
        {
            if (array[i] <= value_b && array[i] >= value_a) {count++;}
        }
        if (count == 1)
        {std::cout << "There is " << count << " value between " << value_a << " and " << value_b << std::endl;}
        else
        {std::cout << "There are " << count << " values between " << value_a << " and " << value_b << std::endl;}
    }
    else
    {
        std::cout << "Values A and B (" << value_a << ") are equal." << std::endl;
    }
}

/* Question 2 */
int* arrange(int array[], int num_of_elements) 
{
    int temp = 0;
    int count = 0;
    int odd_index = 0;
    int even_index = num_of_elements;
    int *arranged_array = new int[num_of_elements];

    for (int i = 0; i < num_of_elements; i++)
    {
        if(array[i] % 2 == 0) // Check if even
        {
            arranged_array[--even_index] = array[i]; // Put at the end of the array and decrement
        }
    }
    for (int i = 0; i < num_of_elements; i++)
    {
        if (array[i] % 2 == 1) // Check if odd
        {
            arranged_array[--even_index] = array[i]; // Put at the end of the array and decrement      
        }
    }
    return arranged_array;
}