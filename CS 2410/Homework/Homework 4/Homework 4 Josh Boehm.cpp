/*
Josh Boehm
13 October 2022
CS 2410
Program 4

Use two sort algorith for previous program (3) :
a. Bubble Sort to sort student's name.
c. Selection Sort to sort Student's letter grade
 
Then use a search methode (linear search, or binary search) to look for specific record in this program.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_TESTS = 5;

class studentType
{
    public:
        string studentFname, studentLname;
        int testScore[NUM_TESTS];
        char grade;

    void readStudentdata(studentType studentRecord[]);
    void assignGrade(studentType studentRecord[]);
    void highestTestgrade(studentType studentRecord[], int& highestgradeofall);
    void displayStudentdata(studentType studentRecord[], int highestgradeofall);
};

void studentType::readStudentdata(studentType studentRecord[])
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
void studentType::assignGrade(studentType studentRecord[])
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
void studentType::highestTestgrade(studentType studentRecord[], int& highestgradeofall)
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
void studentType::displayStudentdata(studentType studentRecord[], int highestgradeofall)
{
    for(int s = 0; s < NUM_STUDENTS; s++)
    {
        if (*max_element(studentRecord[s].testScore, studentRecord[s].testScore + NUM_TESTS) == highestgradeofall)
        {
            cout << studentRecord[s].studentLname << ", " << studentRecord[s].studentFname << endl;
        }
    }
}


int main()
{
    studentType studentRecord[NUM_STUDENTS];
    int highestgradeofall = 0;

    studentRecord->readStudentdata(studentRecord);
    studentRecord->assignGrade(studentRecord);
    studentRecord->highestTestgrade(studentRecord, highestgradeofall);
    studentRecord->displayStudentdata(studentRecord, highestgradeofall);
    return 0;
}