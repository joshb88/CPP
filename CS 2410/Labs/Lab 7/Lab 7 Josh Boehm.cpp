/*
Josh Boehm
4 October 2022
CS 2410
Homework 2

Lab 5

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

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include "account.h"

using namespace std;

int main()
{
    Account account;
    cout << account.getId();
}