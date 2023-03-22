#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>

bool DNA_DFA(std::string s);

int main()
{
    std::string sequence;
    std::getline(std::cin, sequence);
    std::transform(sequence.begin(), sequence.end(), sequence.begin(), ::toupper);
    if (DNA_DFA(sequence) == true) {std::cout << "Valid Sequence." << std::endl;}
    else {std::cout << "Invalid Sequence." << std::endl;}
    std::cout << sequence.length();
}

bool DNA_DFA(std::string s)
{
    for (int i; i < s.length(); i++)
    {   
        if (s[0] == s[1] && (s.starts_with() == 'a' || 't'))
        { return true; }
        else {return false;}
    }
}