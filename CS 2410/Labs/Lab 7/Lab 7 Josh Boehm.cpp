/*
Josh Boehm
4 October 2022
CS 2410
Lab 7
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include "account.h"

using namespace std;

int main()
{
    Account test;
    test.setId(100);
    cout << test.getId();
}