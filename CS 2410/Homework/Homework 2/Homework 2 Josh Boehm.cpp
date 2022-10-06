/*
Josh Boehm
16 September 2022
CS 2410
Homework 2

Program 2 - Structure  MAL-C9-P2
Write a program that reads students' names followed by their test scores. 
The program should output each student's name followed by the test scores and the relevant grade. 
It should also find and print the highest test score and the name of the students having the highest test score.
Student data should be stored in a struct variable of type studentType, which has four components:

studentFName of type string,
studentLName of type string,   
testScore of type int (testScore is between 0 and 100), and 
grade of type char. 

Suppose that the class has 20 students. Use an array of 20 components of type studentType.
Your program must contain at least the following functions:

a. A function to read the students' data into the array.
b. A function to assign the relevant grade to each student.
c. A function to find the highest test score.
d. A function to print the names of the students having the highest test score.

Your program must output each student's name in this form: 
last name followed by a comma, followed by a space, followed by the first name; the name must be left justified. 
Moreover, other than declaring the variables and opening the input and output files, 
the function main should only be a collection of function calls.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_TESTS = 5;

struct studentType
{
    string studentFname, studentLname;
    int testScore[NUM_TESTS];
    char grade;
};

void readStudentdata(studentType studentRecord[]);
void assignGrade(studentType studentRecord[]);
void highestTestgrade(studentType studentRecord[], int& highestgradeofall);
void displayStudentdata(studentType studentRecord[], int highestgradeofall);

int main()
{
    studentType studentRecord[NUM_STUDENTS];
    int highestgradeofall = 0;

    readStudentdata(studentRecord);
    assignGrade(studentRecord);
    highestTestgrade(studentRecord, highestgradeofall);
    displayStudentdata(studentRecord, highestgradeofall);
    return 0;
}

void readStudentdata(studentType studentRecord[])
{
    fstream namefile("names.txt");
    fstream gradefile("grades.txt");
    string firstname, lastname;
    int i = 0;

    while(namefile >> firstname >> lastname)
    {
        studentRecord[i].studentFname = firstname;
        studentRecord[i].studentLname = lastname;
        i++;
    }

    for(int s = 0; s < NUM_STUDENTS; s++)
    {
        for(int g = 0; g < NUM_TESTS; g++)
        {
            gradefile >> studentRecord[s].testScore[g];
        }
    }
}
void assignGrade(studentType studentRecord[])
{
    float average[NUM_STUDENTS];

    for (int s = 0; s < NUM_STUDENTS; s++)
    {
        float gradesum = 0;

        for (int g = 0; g < NUM_TESTS; g++)
        {
            gradesum += studentRecord[s].testScore[g];
        }

         average[s] = gradesum / NUM_TESTS;
        
        if (average[s] > 90)
        {
            studentRecord[s].grade = 'A';
        }
        else if (average[s] > 80)
        {
            studentRecord[s].grade = 'B';
        }
        else if (average[s] > 70)
        {
            studentRecord[s].grade = 'C';
        }
        else if (average[s] > 60)
        {
            studentRecord[s].grade = 'D';
        }
        else if (average[s] > 0)
        {
            studentRecord[s].grade = 'F';
        }
        else
        {
            cout << "That doesn't make sense.";
        }
    }

}
void highestTestgrade(studentType studentRecord[], int& highestgradeofall)
{
    for(int s = 0; s < NUM_STUDENTS; s++)
    {
        //Intialize the value of max and index
        int max = INT_MIN;
        int index = -1;

        // Iterate the array
        for(int i=0; i<NUM_STUDENTS; i++)
        {
            if(studentRecord[s].testScore[i] > max)
            {
                // If current value is greater than max
                // value then replace it with max value
                max = studentRecord[s].testScore[i];
                index = i;
            }
        }
        if (highestgradeofall < max)
        {
            highestgradeofall = max;
        }
    }
}
void displayStudentdata(studentType studentRecord[], int highestgradeofall)
{
    for(int s = 0; s < NUM_STUDENTS; s++)
    {
        if (*max_element(studentRecord[s].testScore, studentRecord[s].testScore + NUM_TESTS) == highestgradeofall)
        {
            cout << studentRecord[s].studentLname << ", " << studentRecord[s].studentFname << endl;
        }
    }
}