#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

/*
Write a C++ function named onlyLowerCase that accepts a string parameter and 
returns another string by removing all characters other than lower case letters in the 
parameter. For instance, if the parameter is "The young girl gave no clear response.", the 
function should return “heyounggirlgavenoclearresponse” . In your main function, read a file 
named “input.txt” and remove all characters except lower case letters in each line and print 
them into “output.txt” using onlyLowerCase function. 
*/

int main()
{
    enum text_input { user_input = 1, file = 2 };
    //std::string in_text;

    int user_choice ;
    std::cin >> user_choice;
    std::cout 
    << "This program will take a text input and remove all but the lower cased letters, including spaces." << std::endl 
    << "Please, specify how you would like to input your text:" << std::endl << std::endl
    << "Enter 1 if you'd like to type yourself." << std::endl
    << "Enter 2 if you'd like to read from a file named 'input.txt'" << std::endl << std::endl;


    // switch (user_choice)
    // {
    // case user_input:
    //     in_text = "";
    //     break;
    // case file:
    //     std::ifstream in_file;
    //     inFile
    // default:
    //     std::cout << "Tha"
    //     break;
    // }
}