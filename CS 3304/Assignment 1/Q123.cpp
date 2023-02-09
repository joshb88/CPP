#include <iostream>
#include <iomanip>
#include <string>

/* Question 1 */

void countBetween(int array[], int num_of_elements, int value_a, int value_b);

/* Question 2 */

int* arrange(int array[], int size);

int main()
{
    int a[] = {3,7,9,15,4,6};
    countBetween(a, 6, 7, 4);
    int *b = arrange(a, 6);
    for (int i = 0; i < 6; i++) 
    {
        std::cout << *(b+i) << " ";
        std::cout << std::endl;
    }

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
    int odd_index = 0;
    int even_index = num_of_elements;
    int *arranged_array = new int[num_of_elements];

    for (int i = 0; i < num_of_elements; i++)
    {
        if (array[i] % 2 == 1) // odd
        {
            if (array[i] < arranged_array[odd_index]) {arranged_array[odd_index++] = array[i];}
        }
    }

    return arranged_array;
}