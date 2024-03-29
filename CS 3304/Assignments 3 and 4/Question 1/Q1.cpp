#include <iostream>
#include <fstream>
#include <sstream>
#include "Linked.h"

int main() 
{
    Stack<int> oddStack;
    Stack<int> evenStack;

    std::ifstream inputFile("input.txt");
    std::string line;

    while (std::getline(inputFile, line)) 
    {
        std::istringstream iss(line);
        int num;

        while (iss >> num) 
        {
            if (num % 2 == 0) 
            {
                if (evenStack.top() == num && !evenStack.empty()) 
                {
                    evenStack.pop();
                } 
                else 
                {
                    evenStack.push(num);
                }
            } 
            else 
            {
                if (oddStack.top() == num && !oddStack.empty()) 
                {
                    oddStack.pop();
                } 
                else 
                {
                    oddStack.push(num);
                }
            }
        }

        std::cout << "Odd Top: ";
        if (oddStack.empty()) 
        {
            std::cout << "NULL";
        } 
        else 
        {
            std::cout << oddStack.top();
        }
        std::cout << "\t\t";

        std::cout << "Even Top: ";
        if (evenStack.empty()) 
        {
            std::cout << "NULL";
        } 
        else 
        {
            std::cout << evenStack.top();
        }
        std::cout << std::endl;
    }

    inputFile.close();
    return 0;
}