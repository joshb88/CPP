/*
Josh Boehm
13 October 2022
CS 2410
Program 4

Use two sort algorith for previous program (3) :
a. Bubble Sort to sort student's name.
b. Selection Sort to sort Student's letter grade

Then use a search method (linear search, or binary search) to look for specific record in this program.
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
void bubbleSortName(studentType s[], int n)
{
   bool swapped = true;
   int j = 0, i = 0;
   string tmp;

   while (swapped)
   {
      swapped = false;
      j++;
      for (int i = 0; i < n - j; i++)
      {
         if ( s[i].studentFname > (s[i + 1].studentFname) )
         {

            tmp = s[i].studentFname;
            s[i].studentFname = s[i + 1].studentFname;
            s[i + 1].studentFname = tmp;

            tmp = s[i].studentLname;
            s[i].studentLname = s[i + 1].studentLname;
            s[i + 1].studentLname = tmp;
            swapped = true;
         }
      }
   }
}
void selectionSortGrade(studentType s[], int n);

int main()
{
    studentType studentRecord[NUM_STUDENTS];

    studentRecord->readStudentdata(studentRecord);
    studentRecord->assignGrade(studentRecord);

    bubbleSortName(studentRecord,NUM_STUDENTS);

    for(int i = 0; i < NUM_STUDENTS; i++)
    {
        cout << studentRecord[i].studentFname << " " << studentRecord[i].studentLname << endl;
    };

    return 0;
}