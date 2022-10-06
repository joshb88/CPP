// Joshua Boehm
// February 22, 2022
// CS 1411 

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Establish the constants for the three chairs used in the Woody furniture company
const float AMERICAN_COLONIAL = 85.00, MODERN = 57.50, FRENCH_CLASSICAL = 127.75;

// Initialize the main function
int main(){

    // Initializes quantity of each chair sold
    int am_qty_sold, modern_qty_sold, french_qty_sold;

    // Initialize variables for the sales of each chair and all chairs
    float american_sales, modern_sales, french_sales, total_sales;

    // Prompt user to input how many American Colonial chairs sold
     cout << "How many American Colonial chairs sold?" << endl;
    
    // Save the quantity of American Colonial chairs sold
    cin >> am_qty_sold;

    // Input verification for American chairs input
    while (am_qty_sold < 0)
    {
        cout <<  endl << "You entered a negative number; try again" 
        << endl << "How many American Colonial chairs sold?" << endl;
        cin >> am_qty_sold;
    }
    

    // Prompt user to input how many Modern chairs sold
    cout <<endl << "How many Modern chairs sold?" << endl;

    // Save the quanitity of Modern chairs sold
    cin >> modern_qty_sold;

    // Input verification for Modern chairs input
    while (modern_qty_sold < 0)
    {
        cout <<  endl << "You entered a negative number; try again." 
        << endl << "How many Modern Chairs sold?" << endl;
        cin >> modern_qty_sold;
    }

    // Prompt the user to input how many French chairs sold
    cout << endl << "How many French chairs sold?" << endl;

    // Save the quantity of French chairs sold
    cin >> french_qty_sold;

    // Input verification for French chairs input
    while (french_qty_sold < 0)
    {
        cout <<  endl << "You entered a negative number; try again." 
        << endl << "How many French chairs sold?" << endl;
        cin >> french_qty_sold;
    }

    // Calculate each chair's sales
    american_sales = am_qty_sold * AMERICAN_COLONIAL,
    modern_sales = modern_qty_sold * MODERN,
    french_sales = french_qty_sold * FRENCH_CLASSICAL,
    total_sales = american_sales + modern_sales + french_sales;

    // Display the sales figures.
    cout << fixed << showpoint << setprecision(2)
    << endl << "The total sales for the American Colonial chairs were: $" << american_sales
    << endl << "The total sales for the Modern chairs were: $" << modern_sales
    << endl << "The total sales for the French Classical were: $" << french_sales
    << endl << "The total sales for all chairs was: $" << total_sales;

    // Terminate the program
    return 0;
}