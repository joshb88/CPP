/*
Josh Boehm
6 October 2022
CS 2410
Lab 7

(The Account class) Design a class name Account that contains :

After LAB 6 is done , we like to use the Account class created above to simulate an ATM machine.  
Create 10 accounts in an array with id 0-9 and initial balance $100.  
The system prompts the user to enter an id , if the id is entered incorrectly, ask the user to enter a correct one.  
Once an id is accepted , the main menu is displayed (look at sample below) .
 
You can enter a choice
1 for viewing the current Balance
2 for withdrawing money
3 for depositing money
4 for exiting the main menu.
 
Once you exit the system will prompt for an id again .  
So once the system starts it will not stop.
 
Sample menu
 
Enter an id :   4      ENTER
Main Menu
1. Check Balance
2. Withdraw
3. Deposit
4. Exit
Enter a Choice   ENTER
The Balance is 100.00
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include "account.h"

using namespace std;

const int NUM_OF_ACCOUNTS = 10;
const string SECTION_BREAK = "\n===================================\n";

int idInputVerified();
void mainMenu(Account[]);

int main()
{
    // Create the bank accounts, based on global variable set above
    Account bank_accounts[NUM_OF_ACCOUNTS];

    
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++)
    {
        bank_accounts[i].setId(i);
        bank_accounts[i].setBalance(100);
        bank_accounts[i].setAnnualInterestRate(.025);
    }

    mainMenu(bank_accounts);
}

int idInputVerified()
{
    int idcheck;
    cout <<
    "\n+---------------------------------+\n"
      "|    Welcome to the ATM program   |" 
    "\n+---------------------------------+\n"
      "|    Enter an ID or -1 to exit:   |\n"
      "+---------------------------------+\n"
      "  Entry:   \t\t\t";
    cin >> idcheck;
    cout << SECTION_BREAK << endl;

    if(idcheck == -1)
    {
        exit(0);
    }

    while(cin.fail() || idcheck < 0 || idcheck > NUM_OF_ACCOUNTS-1) 
    {
        cout << "Please enter an appropriate ID:" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> idcheck;

    }

    return idcheck;
}

void mainMenu(Account a[])
{
    int account_number = idInputVerified();
    double withdrawal_amt, deposit_amt;
    int menu_choice;

    cout <<
    SECTION_BREAK <<
    "Main Menu" <<
    SECTION_BREAK <<
    "1. Check Balance\n" <<
    "2. Withdraw\n" <<
    "3. Deposit\n" <<
    "\n\n\n" <<
    "9. Exit\n" <<
    SECTION_BREAK <<
    "Entry:\t\t\t\t";
    cin >> menu_choice;
    cout << SECTION_BREAK << endl;

    switch (menu_choice)
    {
    case 1:
        cout <<
        SECTION_BREAK <<
        "Current Balance" <<
        SECTION_BREAK <<
        "Your current balance is: " << a[account_number].getBalance() <<
        "\n\nReturning to main menu...\n\n" << SECTION_BREAK << "\n\n" << endl;
        mainMenu(a);

    case 2:
        cout <<
        SECTION_BREAK <<
        "Withdrawal" <<
        SECTION_BREAK <<
        "Enter withdraw amount:\t\t";
        cin >> withdrawal_amt;

        while(cin.fail() || withdrawal_amt > a[account_number].getBalance()) 
        {
            cout << "Please enter an appropriate amount.\n" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout <<"Enter withdraw amount:\t\t";
            cin >> withdrawal_amt;
        }

        a[account_number].withdrawl(withdrawal_amt);

        cout << "Your new balance is:" << setw(15) << right << a[account_number].getBalance() <<
        SECTION_BREAK;

        mainMenu(a);

    case 3:
        cout <<
        SECTION_BREAK <<
        "Deposit" <<
        SECTION_BREAK <<
        "Enter deposit amount:\t\t";
        cin >> deposit_amt;

        while(cin.fail() || deposit_amt > a[account_number].getBalance()) 
        {
            cout << "Please enter an appropriate amount.\n" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout <<"Enter withdraw amount:\t\t";
            cin >> deposit_amt;
        }

        a[account_number].deposit(deposit_amt);

        cout << "Your new balance is:" << setw(15) << right << a[account_number].getBalance() <<
        SECTION_BREAK;

        mainMenu(a);

    case 9:
        cout << "Exiting the menu.\n\n" <<
        SECTION_BREAK;

        mainMenu(a);

    default:
        cout <<
        "Invalid Entry.\n" <<
        "Going back to main menu." <<
        SECTION_BREAK;

        mainMenu(a);
    }
    
}