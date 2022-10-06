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
#include "account.h"

using namespace std;

const int NUM_OF_ACCOUNTS = 10;

int main()
{
    Account bank_accounts[NUM_OF_ACCOUNTS];
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++)
    {
        bank_accounts[i].setId(i);
        bank_accounts[i].setBalance(100);
        bank_accounts[i].setAnnualInterestRate(.025);
    }
}