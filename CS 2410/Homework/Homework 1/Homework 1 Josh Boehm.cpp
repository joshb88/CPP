/*
Joshua Boehm
10 September, 2022
CS 2410

Submit this program This is a Review for CS 1410    MAL-C8-P13
Write a program to calculate students' average test scores and their grades. You may assume the following input data:
Johnson   Marieta     85   83  77   91  76
Aniston     Saboly      80   90   95   93  48
Cooper     Mancini    81   91   90   83  58
Gupta       Piota        70   50   85   73  68
Blair          Coviani    60   90   75   53  98
 
Use three arrays: a  one-dimensional string array to store the students' names, a (parallel) 
two-dimensional integer array to store the test scores, and  one-dimensional double array 
to store average grades  for each student. Your program must contain at least the following 
functions: a function to  read and store  data (student's grade)  into two arrays, a function to 
calculate the average test score and, and a function to  output the results. Have your program 
also output the class average.
=================================================================================================

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const int ROW = 5, COL = 5;
int grades[ROW][COL];
string SECTIONBREAK = "\n==========================================================================\n";


void read(string firstname[],string lastname[],string fullname[])
{
    // Establish variable for the read file
    fstream datafile("data.txt");

    // For each row in the data
    for(int r=0;r < ROW; r++)

    // Take the first and last names, concatenate them as a single string, and assign them to their own variable
    {
        datafile >> firstname[r] >> lastname[r];
        fullname[r] = firstname[r]+" "+lastname[r];

        // Assign each grade in that row to the same record
        for(int c=0;c<COL;c++)
        {
            datafile >> grades[r][c];
        }
    }

    // Used for testing
    // for(int r=0;r < ROW; r++)
    //     {
    //         cout << fullname[r] << " ";
    //         for(int c=0;c<COL;c++)
    //         {
    //             cout << grades[r][c] << " ";
    //         }
    //         cout << '\n';
    //     }

    cout << "The data has been successfully read." << SECTIONBREAK << "\n\n";
}
void calcAverage(float average[], float& classavg)
{

    // For each row...
    for (int r = 0; r < ROW; r++)
    {
        //Establish an accumulator
        int sum = 0;

        // take each column element and...
        for (int c = 0; c < COL; c++)
        {
            // Accumulate the sum
            sum += grades[r][c];
        }
        // Assign that row's sum to an seperate array
        average[r] = static_cast<float>(sum)/COL;
        // Reset the sum for the next row
        sum = 0;

        // Used for testing purposes
        // cout << average[r] << '\n';
    }

    // Establish a running total to average the class
    float classtotal = 0;

    // Start the class averaging
    for (int i = 0; i < ROW; i++)
    {
        classtotal += average[i];
    }
    classavg = classtotal/ROW;
    cout << "The averages have been calculated." << SECTIONBREAK << "\n\n";
    
}
void displayResults(string fullname[], float average[], float classavg)
{
    // Create/Overwrite a file to assign the new information to
    fstream writefile("final results.txt", ios::out);

    // For each row...
    for (int r=0; r < ROW; r++)
    {
        // Write the name first,
        writefile << left << setw(18) << fullname[r] << " ";
        // Display it
        cout << left << setw(18) << fullname[r] << " " << setw(18);
        
        // then go column by column to...
        for (int c = 0; c < COL; c++)
        {
            // take data from the original array and write it to the file...
            writefile << left << setw(3) << grades[r][c] << "\t";
            // and display it in the terminal.
            cout << left << setw(3) << grades[r][c] << "\t";
        }
        // Additionally, add the sum and average to the new file in the corresponding row...
        writefile << "\t" << average[r] << "\t";
        // and display it in the terminal.
        cout << setw(5) << fixed << setprecision(2) << "\t" << average[r] << "\n";
    }

    cout << '\n' << "The class average as a whole is: " << classavg << SECTIONBREAK << endl;
}

int main()
{
    string firstname[ROW], lastname[ROW], fullname[ROW];
    fstream datafile("data.txt");
    float average[ROW];
    float classavg;

    read(firstname, lastname, fullname); 
    calcAverage(average, classavg);
    displayResults(fullname, average, classavg);

}