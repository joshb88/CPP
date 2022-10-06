#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

const int n = 12;


int search(int array[n], int target)
{
    // Going through array sequentially
    for (int i = 0; i < n; i++)

        if (array[i] == target)
            return i;
        return -1;
}

int main()
{
    int array[n], i, result;
    int target = 81;
    //sort(array,array+n);

    fstream searchfile("search.txt");
    

    for (i = 0; i < n; i++)
        searchfile >> array[i];
    
    result = search(array, target);

    cout << result;
}