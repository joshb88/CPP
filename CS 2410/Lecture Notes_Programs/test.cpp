#include <iostream>
#include <string>

using namespace std;

struct Student
{
    int studentid;
    string name;
    short yearinschool;
    double gpa;
};

int main()
{
    Student stud1;
    cout << stud1.gpa;
}