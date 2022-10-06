#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int num = 3;

class movie {
public:
    string title, director;
    int year, time;
    double cost, firstRev, profit;
    
public:
    void ReadMovieData(string title, string director, int year, int time, double cost, double rev);
    double FindProfitorLost(double cost, double rev);
    void DisplayResult();
};

void movie::ReadMovieData(string t, string d, int y, int min, double c, double r) {
    title = t;
    director = d;
    year = y;
    time = min;
    cost = c;
    firstRev = r;
    profit = FindProfitorLost(c, r);
}
double movie::FindProfitorLost(double cost, double rev) {
    return rev - cost;
}
void movie::DisplayResult() {
    cout << "Title: " << title << endl;
    cout << "Directed by: " << director << endl;
    cout << "Year released: " << year << endl;
    cout << "Running time: " << time << " mins" << endl;
    cout << "First year revenue: " << firstRev << endl;
    cout << "Profit: " << profit << endl;
}
int main() {
    fstream titles("title.txt", ios::in);
    fstream directors("director.txt", ios::in);
    fstream years("release date.txt", ios::in);
    fstream times("runtime.txt", ios::in);
    fstream costs("cost.txt", ios::in);
    fstream revenues("revenue.txt", ios::in);
    string title, director;
    int year, time;
    double cost, revenue;
    movie movs[num];

    int i = 0;

    for (int i = 0; i < num; i++) {
        getline(titles, title);
        getline(directors, director);
        years >> year;
        times >> time;
        costs >> cost;
        revenues >> revenue;
        movs[i].ReadMovieData(title, director, year, time, cost, revenue);
    }
    titles.close();
    directors.close();
    years.close();
    times.close();
    costs.close();
    revenues.close();

    for (int i = 0; i < num; i++) {
        movs[i].DisplayResult();
    }
    return 0;
}