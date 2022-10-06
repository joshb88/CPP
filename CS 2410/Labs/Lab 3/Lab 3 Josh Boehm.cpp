/*
Joshua Boehm
15 September 2022
CS 2410
Lab 3

Use Lab 2, to use an array of structure movie.
Create an input file (s) to enter information (title, year released, cost, time, ....) for this array of movies.  Read data from these files , store them in proper arrays , then display them on screen.
you must use three functions and pass structure as an arqument, or primative arquments).  Functions are 
ReadmovieData
FindProfitorLost
DisplayResult
Format the output in specific order (movie name, or time, or cost).
=================================================================================================
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct MovieData
{
   string title;    // Movie title
   string director; // Director
   int year;        // Year released
   int length;      // Running time in minutes
   int cost;     // Production cost
   int revenue;  // First year revenue
   int profit;  // First year profit
   
};

string SECTIONBREAK = "\n==========================================================================\n";
const int NUM_OF_MOVIES = 5;
void readMovieData(MovieData[]);
void displayMovie(MovieData[]);
void findProfitorLoss(MovieData[]);

int main()
{
    MovieData movie[NUM_OF_MOVIES];
    readMovieData(movie);
    findProfitorLoss(movie);
    displayMovie(movie);
}

void readMovieData(MovieData m[])
{
    fstream titlefile("title.txt");
    fstream directorfile("director.txt");
    fstream releasedatafile("release date.txt");
    fstream runtimefile("runtime.txt");
    fstream costfile("cost.txt");
    fstream revenuefile("revenue.txt");

    
    for(int i = 0; i < NUM_OF_MOVIES; i++)
        {
            cout << SECTIONBREAK;
            getline(titlefile, m[i].title);
            cout << "For movie " << (i+1) << ", retrieved title name: " << m[i].title << endl;
            getline(directorfile, m[i].director);
            cout << "For movie " << (i+1) << ", retrieved director name: " << m[i].director << endl;
            releasedatafile >> m[i].year;
            cout << "For movie " << (i+1) << ", retrieved release date: " << m[i].year << endl;
            runtimefile >> m[i].length;
            cout << "For movie " << (i+1) << ", retrieved runtime: " << m[i].length << endl;
            costfile >> m[i].cost;
            cout << "For movie " << (i+1) << ", retrieved cost: " << m[i].cost << endl;
            revenuefile >> m[i].revenue;
            cout << "For movie " << (i+1) << ", retrieved revenue: " << m[i].revenue << endl;

            if((i+1) < NUM_OF_MOVIES)
                cout << '\n' << "All data has been retrieved; moving on to the next movie " << (i+2) << ".";
            else
                cout << '\n' << "Process completed: All movies have been stored.";
            cout << SECTIONBREAK;
        }

    
}

void findProfitorLoss(MovieData m[])
{
    for (int i = 0; i < NUM_OF_MOVIES; i++)
    {
        m[i].profit = m[i].revenue - m[i].cost;
    }

}

void displayMovie(MovieData m[])
{
    for(int i = 0; i < NUM_OF_MOVIES; i++)
        cout << 
        "\nTitle             : " << m[i].title <<
        "\nDirector          : " << m[i].director <<
        "\nReleased          : " << m[i].year <<
        "\nRunning Time      : " << m[i].length << " minutes" <<
        "\nFirst Year Profit : $" << m[i].profit << endl;
} 