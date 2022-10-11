/*
Josh Boehm
4 October 2022
CS 2410
Homework 2

Lab 6

(The Account class) Design a class name Account that contains :
An int data field named id for the account.
A double data field named balance for the account.
A double data field named annualInterestRate that stores the current interest rate.
A no-arg constructor that creates a default account with id 0, balance 0, and annualInterestRate 0;
The accessor and mutator functions for id, balance and annualInterestRate.
A function named getMonthlyInterestRate() that returns the monthly Interest Rate.
A function named withdraw( amount ) that withdraw specific amount from account.
A function named deposit( amount ) that deposit specific amount to the account.

Draw the UMLdiagram for the class.
Implement the class.
Write a test program that creates an account object with an account ID of 1122, a balance of 20000,
and an annual interest rate of 4.5%.  Use the withdraw function to withdraw 2500, use deposit function to deposit 3000,
and print the balance, the monthly interest.
*/


/*
+----------------------------------+
|             Account              |
+----------------------------------+
|  - id                            |
|  - balance                       |
|  - annualInterestRate            |
+----------------------------------+
|  + getID()                       |
|  + getBalance()                  |
|  + getAnnualInterestRate()       |
|  + getMonthlyInterestRate()      |
|                                  |
|                                  |
|                                  |
|                                  |
|                                  |
+----------------------------------+
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include "account.h"

using namespace std;

// class Account
// {
//     private:
//         int id;
//         double balance;
//         double annualInterestRate;

//     public:

//     Account()
//     {
//         id = 0;
//         balance = 0;
//         annualInterestRate = 0;
//     }

//     int getId()                                 const{         return id;            }
//     double getBalance()                         const{       return balance;         }
//     double getAnnualInteresteRate()             const{  return annualInterestRate;   }

//     void setId(int setid)                            {         id = setid;           }
//     void setBalance(double setbalance)               {      balance = setbalance;    }
//     void setAnnualInterestRate(double setAIR)        {  annualInterestRate = setAIR; }
//     void withdrawl(double amount)                    {      balance -= amount;       }
//     void deposit(double amount)                      {      balance += amount;       }
//     double getMonthlyInterestRate()                  { return annualInterestRate/12; }

// };

int main()
{
    Account account;
    account.setId(1122);
    account.setBalance(20000);
    account.setAnnualInterestRate(.045);

    account.withdrawl(2500);
    account.deposit(3000);

    cout << fixed << setprecision(2)
         << left << setw(30) << "The balance is:" << right << setw(10) << account.getBalance() << endl
         << left << setw(30) << "The monthly interest is:" << setw(10) << right << account.getMonthlyInterestRate() * account.getBalance() << endl;
}