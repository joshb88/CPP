#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

// The regex for the language is (AA+TT)(AA+TT)*
int dfa = 0;
void state_s(char c);
void state_1(std::string c);
void state_2(std::string c);
void state_3(std::string c);
void state_9(std::string c);
bool dna_dfa(std::string s);

int main()
{
    // std::string sequence;
    // std::cout << "Enter a DNA sequence to check:" << std::endl;
    // std::getline(std::cin, sequence);
    // std::transform(sequence.begin(), sequence.end(), sequence.begin(), ::toupper);
    // std::cout << "The resultant sequence entered was: " << sequence << std::endl;

    // if (dna_dfa(sequence)) { std::cout << "VALID SEQUENCE."; }
    // else { std::cout << "INVALID SEQUENCE."; }

    std::string strings[] = {"AATT", "AATACGTTAAAA", "AAGAACAA", "AATTTTAAAA"};

    for (int i = 0; i < 4; ++i)
    {
        std::cout << strings[i] << " : ";
        if (dna_dfa(strings[i])) { std::cout << "VALID SEQUENCE." << std::endl; }
        else { std::cout << "INVALID SEQUENCE." << std::endl; }
        dfa=0;
    }
}

void state_s(char c)
{
    switch (c)
    {
    case 'A':
        dfa = 1;
        break;
    case 'T':
        dfa = 2;
        break;
    case 'G':
        dfa = 9;
        break;
    case 'C':
        dfa = 9;
        break;
    default:
        dfa = -1;
        break;
    }
}
void state_1(char c)
{
    switch (c)
    {
    case 'A':
        dfa = 3;
        break;
    case 'T':
        dfa = 9;
        break;
    case 'G':
        dfa = 9;
        break;
    case 'C':
        dfa = 9;
        break;
    default:
        dfa = -1;
        break;
    }
}
void state_2(char c)
{
    switch (c)
    {
    case 'A':
        dfa = 9;
        break;
    case 'T':
        dfa = 3;
        break;
    case 'G':
        dfa = 9;
        break;
    case 'C':
        dfa = 9;
        break;
    default:
        dfa = -1;
        break;
    }
}
void state_3(char c)
{
        switch (c)
    {
    case 'A':
        dfa = 1;
        break;
    case 'T':
        dfa = 2;
        break;
    case 'G':
        dfa = 9;
        break;
    case 'C':
        dfa = 9;
        break;
    default:
        dfa = -1;
        break;
    }
}
void state_9(char c)
{
    dfa = -1;
}
bool dna_dfa(std::string s)
{
    for (std::string::iterator i = s.begin(); i != s.end(); ++i)
    {
        switch (dfa)
        {
        case 0:
            state_s(*i);
            break;
        case 1:
            state_1(*i);
            break;
        case 2:
            state_2(*i);
            break;
        case 3:
            state_3(*i);
            break;
        case 9:
            state_9(*i);
            break;
        default:
            return false;
        }
    }
    if (dfa == 3) { return true; }
    else { return false; }
}