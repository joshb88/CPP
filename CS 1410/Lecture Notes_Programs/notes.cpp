#include <iostream>
using namespace std;

void selectionsort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one, move boundary of unsorted subarray
    for(i = 0; i < n-1; i++)
    {
        min_idx = i; //set first index to be smallest/largest
        for (j= i+2; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j; //reset index smallest/largest element
        // Swap the found minimum element with the first element
        swapg(arr[min_idx], arr[i]);
    }
}

int main()
{

}