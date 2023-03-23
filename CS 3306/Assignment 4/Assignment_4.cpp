/*
In this assignment, you will implement a deterministic finite automaton (DFA) 
using C++ programming language to test if an input DNA sequence matches a 
regular expression. 
1.	The alphabet for generating DNA sequences is {A, T, G, C}. Design a 
deterministic finite automaton to recognize the regular expression 
(AA+TT)(AA+TT)*. 
2.	Write a program which asks the user to input a DNA sequence. 
The program should be able test if the input matches the regular expression 
given in (1). You MUST implement DFA from (1) to check if the DNA sequence is a 
part of the regular expression or not. 
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>

bool DNA_DFA(std::string s);

int main()
{
    std::string sequence;
    std::cout << "Enter a DNA sequence to check:" << std::endl;
    std::getline(std::cin, sequence);
    std::transform(sequence.begin(), sequence.end(), sequence.begin(), ::toupper);

    if (DNA_DFA(sequence) == true) {std::cout << "Valid Sequence." << std::endl;}
    else {std::cout << "Invalid Sequence." << std::endl;}
}

bool DNA_DFA(std::string s)
{
    // Reject sequences with neither A nor T.
    if ((s.find('A') == std::string::npos) && (s.find('T') == std::string::npos))
    {
        std::cout << "did not find A nor t" <<std::endl;
        return false;
    }
    
    else 
    { 
        for (std::string::iterator i = s.begin(); i != s.end(); ++++i)
        {
            if (*i != *(i+1)) {return false;}
        }
        return true; 
    }
    // for (int i; i < s.length(); i++)
    // {   
    //     if (s[0] == s[1] && (s.))
    //     { return true; }
    //     else {return false;}
    // }
}