/*
Joshua Boehm
8 September, 2022

Create a text file (int, string, or double) then read tit in an array or vector , use linear & binary search function i gave you on (9/8/2022)
implement it in a c++ program that reads data and loook for a target in the array.  upload it for grading
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include  <algorithm>

using namespace std;

int binarySearch(int[], int, int, int);
int search(int[], int);
void show(int[]);
void read(int[]);

const int n = 12;


int main()
{
    int lab8[n];
    int searchparameter = 1988;
    read(lab8);
    cout << "The array we will use to search is: \n";
    show(lab8);
    cout << "\n\nSearching with a linear search using the value: " << searchparameter << endl;
    cout << "The index of the array with " << searchparameter << " is " << search(lab8, searchparameter) << "." << endl;

    cout << "In order to use binary search, we need to first sort the array." << endl;
    sort(lab8, lab8+n);        //defined in algorithm preprocessor directive

    cout << "\n\n The array after sorting is : \n";
    show(lab8);

    cout << "\n\nNow that the array is sorted, we can use the binary search." << endl;
    cout << "The index of the array with " << searchparameter << " is " << binarySearch(lab8, searchparameter, 0, 11) << "." << endl;

}

int binarySearch(int array[], int x, int low, int high)
{   // Repeat until the pointers low and high meet each other
    while (low <= high) 
    {
     int mid = low + (high - low) / 2;

      if (array[mid] == x)
         return mid;
      else if (array[mid] < x)
          low = mid + 1;
      else
          high = mid - 1;
    }
   return -1;
}
int search(int array[n], int target)
{
    // Going through array sequentially
    for (int i = 0; i < n; i++)
        if (array[i] == target)
        return i;
    return -1;
}
void show(int a[n])
{     
    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
}
void read(int array[n])
{
    fstream infile("unsorted.txt");
    for(int i = 0; i < n; i++)
        infile >> array[i];
        
}