/*
Joshua Boehm
13 September, 2022
CS 2411

a. Write a program that uses a structure named MovieData to store the following information about movie:
Title, Director, Year Released, Running Time in minute
The program should create two MovieData variables, store values in their members and pass each one , 
into a function that displays the information about movie in a clearly formatted manner

b. When you finish with this program modify above program to include two additional members 
that hold the movie’s production costs and first–year revenues.  
Modify that function display to the movie data to display the title, 
director, release year, running time, and first year’s profit or lost
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <locale>

using namespace std;

struct MovieData
{
   string title;    // Movie title
   string director; // Director
   int year;        // Year released
   int length;      // Running time in minutes
   int cost;     // Production cost
   int revenue;  // First year revenue
   
};

string SECTIONBREAK = "\n==========================================================================\n";
const int NUM_OF_MOVIES = 2;
void displayMovie(MovieData m1);
void readMovieData(MovieData m1);

int main()
{

   // Create two MovieData variables.
   MovieData movie1, movie2;
   movie1.title = "War of the Worlds"; // Assign values to movie1's members.
   movie1.director = "Byron Haskin";
   movie1.year = 1953;
   movie1.length = 88;
   movie1.cost = 2000000;
   movie1.revenue = 2000000;

   // Assign values to movie2's members.
   movie2.title = "War of the Worlds";
   movie2.director = "Stephen Spielberg";
   movie2.year = 2005;
   movie2.length = 118;
   movie2.cost = 132000000;
   movie2.revenue = 603900000;

    // MovieData movie[NUM_OF_MOVIES];
    // for(int i = 0; i < NUM_OF_MOVIES; i++)
    //     {
    //         cout << "Enter the title for movie " << (i+1) << ": ";
    //         getline(cin >> ws, movie[i].title);
    //         cout << "Enter the director for movie " << (i+1) << ": ";
    //         getline(cin, movie[i].director);
    //         cout << "Enter the release year for movie " << (i+1) << " ";
    //         cin >> movie[i].year;
    //         cout << "Enter the length (in minutes) for movie " << (i+1) << ": ";
    //         cin >> movie[i].length;
    //         cout << "Enter the cost (in dollars) for movie " << (i+1) << ": ";
    //         cin >> movie[i].cost;
    //         cout << "Enter the revenue (in dollars) for movie " << (i+1) << ": ";
    //         cin >> movie[i].revenue;
    //         cout << "\n";

    //     }

//    // Display movie1's data.
//    displayMovie(movie[0]);
//    cout << endl;
   
//    // Display movie2's data.
//    displayMovie(movie[1]);

   // Display movie1's data.
   displayMovie(movie1);
   cout << endl;
   
   // Display movie2's data.
   displayMovie(movie2);
   
   return 0;
}
// The displayMovie function displays the data in the  member variables of the MovieData structure passed  as an argument.                                    *
void displayMovie(MovieData m)
{
    cout << "\nTitle             : " << m.title;
    cout << "\nDirector          : " << m.director;
    cout << "\nReleased          : " << m.year;
    cout << "\nRunning Time      : " << m.length << " minutes";
    cout << "\nFirst Year Profit : $" << (m.revenue - m.cost) << endl;
} 