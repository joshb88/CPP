/*
Joshua Boehm
21 September 2022
CS 2410
Lab 4

Convert movie program  to array of objects, then make a 5 minuts code review in class n your conversion
=================================================================================================
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

string SECTIONBREAK = "\n============================================================\n";
const int NUM_OF_MOVIES = 5;

class movie
{
private:
    string title;    // Movie title
    string director; // Director
    int release_year;        // Year released
    int runtime;      // Running time in minutes
    int cost;     // Production cost
    int revenue;  // First year revenue
public:
    void setTitle()                  { cout << "Enter a title:\t"; getline(cin >> ws, title); };
    void setDirector()               { cout << "Enter a director:\t"; getline(cin >> ws, director); };
    void setReleaseyear()            { cout << "Enter a release year:\t"; cin >> release_year; };
    void setRuntime()                { cout << "Enter a runtime:\t"; cin >> runtime; };
    void setCost()                   { cout << "Enter a cost:\t"; cin >> cost; };
    void setRevenue()                { cout << "Enter a revenue:\t"; cin >> revenue; };

    string getTitle() const { return title; };
    string getDirector() const { return director; };
    int getReleaseyear() const { return release_year; };
    int getRuntime() const {return runtime; };
    int getCost() const { return cost; };
    int getRevenue() const { return revenue; };

    void readAllFromUser(movie []);
    void readAllFromManyFiles(movie []);
    void displayAll(movie []);

};

void movie::readAllFromUser(movie m[])
{  
    for (int i = 0; i < NUM_OF_MOVIES; i++)
    {
        m[i].setTitle();
        m[i].setDirector();
        m[i].setReleaseyear();
        m[i].setRuntime();
        m[i].setCost();
        m[i].setRevenue();
        cout << endl;
    }
}

void movie::readAllFromManyFiles(movie m[])
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
            releasedatafile >> m[i].release_year;
            cout << "For movie " << (i+1) << ", retrieved release date: " << m[i].release_year << endl;
            runtimefile >> m[i].runtime;
            cout << "For movie " << (i+1) << ", retrieved runtime: " << m[i].runtime << endl;
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

void movie::displayAll(movie m[])
{
    for(int i = 0; i < NUM_OF_MOVIES; i++)
    {
    cout << SECTIONBREAK << "Movie " << i + 1 << SECTIONBREAK
    << left << setw(30) << "Title: " << right << setw(30) << m[i].getTitle() << endl
    << left << setw(30) << "Director: " << right << setw(30) <<  m[i].getDirector() << endl
    << left << setw(30) << "Release Year: " << right << setw(30) << m[i].getReleaseyear() << endl
    << left << setw(30) << "Running Time: " << right << setw(30) << m[i].getRuntime() << endl
    << left << setw(30) << "Cost: " << right << setw(30) << m[i].getCost() << endl
    << left << setw(30) << "Revenue: " << right << setw(30) << m[i].getRevenue() << endl << endl;
    }
}

int main()
{
    movie movie[NUM_OF_MOVIES];

    movie->readAllFromManyFiles(movie);
    movie->displayAll(movie);
}