/*
Joshua Boehm
25 August, 2022
CS 2410


Write an interactive program that uses 3 different functions.  Called Read, Calculate, and Display.
Read function will read a set of data such as below from an input file  called   number.txt
10 20 30 40 50 60 70 
11 21 31 41 51 61 71
12 22 32 42 52 62 72
This function stores data in an appropreate array.  
Functinon Calculate will read each row and find sum and average of each row and save it in a proper array
Function Display , will display set of grade . sum of grades, and average of grades.  Make sure you are using proper spacing and have two digists of decimal for each grade
Main program will call these three functions.  Input your information, and submit only .cpp (source code) 
==================================================================================
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const int row = 5;
const int col = 7;
int stgrade[row][col];
int r, c;
int total[row];
float average[row];
string strname[row];
char letter[row];


template <class T>
void swap_data(T& x, T& y)
{
    T t;
    t = x;
    x = y;
    y = t;
}
void Swapname(string& n1, string& n2)
{
    string temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}
void Read()
{
    // Open the file from which to read
    fstream gradefile("grades.txt");
    fstream namefile("names.txt");

    int i=0;

    while(i < 20 && getline(namefile, strname[i++]))

    // For each row...
    for (r = 0; r < row; r++)
    {   
        // and corresponding column...
        for (c = 0; c < col; c++)
        {
            // Assign the grade to the array sequentially
            gradefile >> stgrade[r][c];
        }
 
    }
}
void Calculate()
{
    //Establish an accumulator
    int sum = 0;

    // For each row...
    for (r = 0; r < row; r++)
    {
        // take each column element and...
        for (c = 0; c < col; c++)
        {
            // Accumulate the sum
            sum += stgrade[r][c];
        }
        // Assign that row's sum to an seperate array
        total[r] = sum;
        // Reset the sum for the next row
        sum = 0;
        // Take the row's average and assign it to a seperate array
        average[r] = total[r]/col;

        // Conditionally check the averages to determine the letter grade and then assign to letter.
        if(average[r] >= 90)
        {
            letter[r] = 'A';
        }
        else if(average[r] >= 80)
        {
            letter[r] = 'B';
        }
        else if(average[r] >=70)
        {
            letter[r] = 'C';
        }
        else if(average[r] >= 60)
        {
            letter[r] = 'D';
        }
        else if(average[r] < 60)
        {
            letter[r] = 'F';
        }
    }
}
void Display()
{    int r, c;
    // Create/Overwrite a file to assign the new information to
    fstream writefile("student record.txt", ios::out);

    // For each row...
    for (r=0; r < row; r++)
    {
        // Write the name first,
        writefile << left << setw(18) << strname[r] << " ";
        // Display it
        cout << left << setw(18) << strname[r] << " " << setw(18);
        
        // then go column by column to...
        for (int c = 0; c < col; c++)
        {
            // take data from the original array and write it to the file...
            writefile << left << setw(3) << stgrade[r][c] << "\t";
            // and display it in the terminal.
            cout << left << setw(3) << stgrade[r][c] << "\t";
        }
        // Additionally, add the sum and average to the new file in the corresponding row...
        writefile << total[r] << "\t" << average[r] << "\t";
        // and display it in the terminal.
        cout << setw(5) << fixed << setprecision(2) << total[r] << "\t" << average[r] << "\t";

        // Lastly, add the letter graade to the new file in the corresponding row...
        writefile << setw(5) << letter[r] << endl;
        // and display it in the terminal.
        cout << setw(5) << letter[r] << endl;
    }
}
void SortName()
{
    int r,c,j;
    for(r=0;r < row;r++)
    {
        for(j = 0; j < row-1; j++)
        {
            if(strname[j] > strname[j+1])
            {
                // Swap names
                string tempname = strname[j];
                strname[j] = strname[j+1];
                strname[j+1] = tempname;

                // Swap totals
                int temptotal = total[j];
                total[j] = total[j+1];
                total[j+1] = temptotal;

                // Swap average
                double tempaverage = average[j];
                average[j] = average[j+1];
                average[j+1] = tempaverage;

                // Swag grades
                for (c=0; c < col; c++)
                {
                    int tempgrade = stgrade[j][c];
                    stgrade[j][c] = stgrade[j+1][c];
                    stgrade[j+1][c] = tempgrade;
                }

                // Swap letter grade
                char templetter = letter[j];
                letter[j] = letter[j+1];
                letter[j+1] = templetter;

            }
        }
    }
}

int main()
{
    // Call all the above functions
    Read();
    Calculate();
    SortName();
    Display();
    return 0;
}