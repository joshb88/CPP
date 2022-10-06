/*
Joshua Boehm
10 March, 2022
CS 1411
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <stdlib.h>

using namespace std;

// Establish a constant for the discounted rate
const float DISCOUNT = 0.25;

// Constants for menu options
const string ERROR_MESSAGE = "Invalid Entry. Please, enter a valid choice.",
             QUIT = "Exiting Program.";

// Constants for destinations
const string HAWAII = "Hawaii", 
             BAHAMAS = "Bahamas", 
             CANCUN = "Cancun";

// Constants for airlines
const string USAIRWAYS = "US Airways",
             DELTA = "Delta",
             SOUTHWEST = "Southwest";


int main(){

    // Establish destination variables for destination menu
    char destination_choice;
    string destination;

    // Display menu for destination selection
    cout << "Choice a destination you would like to fly to:" << endl <<
            "[a] Hawaii" << endl <<
            "[b] Bahamas" << endl <<
            "[c] Cancun" << endl <<
            "Enter either [a], [b], or [c]." << endl;
    
    // Get user input for destination
    cin >> destination_choice;

    // Verify input was valid
    while (!(destination_choice == 'a' || destination_choice == 'b' || destination_choice == 'c')){
        cout << ERROR_MESSAGE << endl;
        cin >> destination_choice;}

    // Set destinaion as Hawaii
    if (destination_choice == 'a'){
        destination = HAWAII;
    }

    // Set destination as Bahamas
    else if (destination_choice == 'b')
        destination = BAHAMAS;

    // Set destination as Cancun
    else
        destination = CANCUN;

    // Display the destination that was chosen
    cout << "You selected " << destination << "." << endl << endl;

    /*------------------------------------------------------------------------------------------------------------------------
    =========================================================================================================================*/
    
    // Establish variables for airline menu
    char airline_choice;
    string airline;
    
    // Display menu for airline selection
    cout << "Choice an airline you would like to fly with:" << endl <<
            "[a] US Airways" << endl <<
            "[b] Delta" << endl <<
            "[c] Southwest" << endl <<
            "Enter either [a], [b], or [c]." << endl;

    // Get user input for airline selection
    cin >> airline_choice;

    // Inpur validation for airline choice
    while (!(airline_choice == 'a' || airline_choice == 'b' || airline_choice == 'c')){
        cout << ERROR_MESSAGE << endl;
        cin >> airline_choice;}

    // Switch structure to set destination
    switch (airline_choice)
    {
    case 'a':
        airline = USAIRWAYS;
        break;
    case 'b':
        airline = DELTA;
        break;
    default:
        airline = SOUTHWEST;
        break;
    }

    // Display the airline that was chosen
    cout << "You selected " << airline << "." << endl << endl;

    /*------------------------------------------------------------------------------------------------------------------------
    =========================================================================================================================*/
    
    // Establish variables for airfare and passengers
    float airfare;
    int passenger_choice, total_passengers;

    // Read and validate input from the user about airfare
    cout << "Enter a dollar amount (more than zero) that you would like to pay for airfare: " << endl;
   
    while(true){                           // Loops until valid input
        cin >> airfare;
        if (cin.good() and airfare > 0)    // If non-negative and an actual integer, displays input
        {
            cout << fixed << setprecision(2) << "You entered $" << airfare << "." << endl << endl;
            break;
        }
        else                               // If not...
        {
            cin.clear();                   // Clears input
            cin.ignore(100, '\n');         // Ignores 100 characters up to the newline character
            cout << ERROR_MESSAGE << endl; // Displays error message
        }
    }

    

    // Display menu for declaration of passengers 
    cout << "How many passengers are there in total?:" << endl <<
            "[1] One passenger" << endl <<
            "[2] Two passengers" << endl <<
            "[3] Three passengers" << endl <<
            "[4] Four passengers" << endl <<
            "Enter either [1], [2], [3], or [4]." << endl;

    // Get user input for declaration of passengers, with input validation
    while(true){                           // Loops until valid input
        cin >> passenger_choice;
        if (!(cin.good() and passenger_choice > 0))
        {
            cin.clear();                   // Clears input
            cin.ignore(100, '\n');         // Ignores 100 characters up to the newline character
            cout << ERROR_MESSAGE << endl; // Displays error message
        }
        else
        {
            break;
        }
    }


    // Switch structure to set and display number of passengers
    switch (passenger_choice)
    {
    case 1:
        total_passengers = 1;
        cout << "You chose " << total_passengers << " passenger." << endl << endl;
        break;
    case 2:
        total_passengers = 2;
        cout << "You chose " << total_passengers << " passengers." << endl << endl;
        break;
    case 3:
        total_passengers = 3;
        cout << "You chose " << total_passengers << " passengers." << endl << endl;
        break;
    default:
        total_passengers = 4;
        cout << "You chose " << total_passengers << " passengers." << endl << endl;
        break;
    }


    /*------------------------------------------------------------------------------------------------------------------------
    =========================================================================================================================*/

    // Establish variables for the minor passengers
    int minor_passengers;
    char minor_passenger_choice;

    // Get input from user about how many of passengers are under 18.
    if (total_passengers == 1)          // Properly written english for 1 passenger
    {
        cout << "Is the (only) passenger under the age of 18?: " << endl <<
        "[y] for Yes" << endl <<
        "[n] for No" << endl;
        cin >> minor_passenger_choice;
        
        // Validate input for selection above
        while (!(minor_passenger_choice == 'y' || minor_passenger_choice == 'n'))
        {
            cout << ERROR_MESSAGE << endl;
            cin >>minor_passenger_choice;
        }

        if (minor_passenger_choice == 'y') // If they indicated the only passenger was a minor
        {
            minor_passengers = 1;          // Set the variable to reflect the input
            cout << "You have indicated that your passenger IS a minor" << endl;
        }
        else                               // Otherwise,
        {
            minor_passengers = 0;          // Set the variable to reflect the input
            cout << "You have indicated that your passenger IS NOT a minor" << endl;
        }
    }
    else
    {
        cout << "Of the " << total_passengers << " passengers, how many are under the age of 18?: " << endl <<
        "Enter a (whole, positive) number which is equal to or less than your total passengers." << endl;

        // Validate input to ensure input is an integer and less than total passengers 
        while(true)                            // Loops until valid input
        {                          
            cin >> minor_passengers;
            if (!(cin.good() && minor_passengers <= total_passengers && minor_passengers >= 0))
            {
                cin.clear();                   // Clears input
                cin.ignore(100, '\n');         // Ignores 100 characters up to the newline character
                cout << ERROR_MESSAGE << endl; // Displays error message
            }
            else
            {
                break;                         // All went well, carrying on.
            }
        }

        // Print proper english depending on whether or not the input has minors
        if (!(minor_passengers == 0)) 
        {
            cout << "You have indicated that there are " << minor_passengers << " minors in your party." << endl << endl;
        }
        else
        {
            cout << "You have indicated that there are no minors in your party" << endl << endl;
        }
    }

    /*------------------------------------------------------------------------------------------------------------------------
    =========================================================================================================================*/

    // Variables to calculate and clarify adult passengers and costs
    int adult_passengers = total_passengers - minor_passengers;
    float adult_airfare = adult_passengers * airfare,
    minor_airfare = (airfare * DISCOUNT) * minor_passengers,
    total_cost = adult_airfare + minor_airfare;

    // Calculate ticket pricing depending on the party size of the user (based on inputs given)
    cout << left << setw(65) << "To recap: " << endl <<
            left << setw(65) << "You've entered that your desired destination is:" << right << setw(10) << destination << endl <<
            left << setw(65) << "You've entered that your desired airline is:" << right << setw(10) << airline << endl <<
            left << setw(65) << "You've entered that your airfare is:" << right << setw(10) << fixed << setprecision(2) << airfare << endl <<
            left << setw(65) << "You've indicated your party size is:" << right << setw(10) << total_passengers << endl <<
            left << setw(65) << "Adults in party:" << right << setw(10) << adult_passengers << endl <<
            left << setw(65) << "Minors in party:" << right << setw(10) << fixed << setprecision(2) << minor_passengers << endl <<
            left << setw(65) << "Ticket price for adults:" << right << setw(10) << fixed << setprecision(2) << adult_airfare << endl <<
            left << setw(65) << "Ticket price for minors:" << right << setw(10) << minor_airfare << endl <<
            left << setw(65) << "Total cost:" << right << setw(10) << fixed << setprecision(2) << total_cost << endl;



    return 0;
}