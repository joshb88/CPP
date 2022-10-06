#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main(){
    int value[]={ 5, 27, 27, 67, 22, 3, 1 };
    cout << 3 * value[1]<<endl;
    cout << ++value[3] + value[3]<<endl;
    cout << value[4]++ + value[1];

    return 0;
}