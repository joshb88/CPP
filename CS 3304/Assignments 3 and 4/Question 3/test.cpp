#include <iostream>
using namespace std;

// Hash function H(x) = 3*x + 2 (mod 13)
int hashFunc(int x) {
    return (3*x + 2) % 13;
}

// Insert an integer in the hash table
void insert(int arr[], int x) {
    int idx = hashFunc(x);  // Calculate the hash value
    while (arr[idx] != 0) {  // Handle collisions using linear probing
        idx = (idx + 1) % 13;
    }
    arr[idx] = x;  // Insert the integer
}

int main() {
    int arr[13] = {0};  // Create an array of 13 elements, initialized to 0
    int values[] = {26, 42, 5, 44, 92, 38, 40, 45, 12, 57, 80, 31};
    int n = sizeof(values) / sizeof(values[0]);  // Calculate the size of the array

    // Insert the given integers in the order given
    for (int i = 0; i < n; i++) {
        insert(arr, values[i]);
    }

    // Display the final hash table
    for (int i = 0; i < 13; i++) {
        cout << i << ": " << arr[i] << endl;
    }

    return 0;
}