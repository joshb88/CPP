#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int num = 100;
    int* ptr = &num;
    cout << num << endl << ptr << endl;

    *ptr = 25;
    cout << num << endl << *ptr << endl;
}