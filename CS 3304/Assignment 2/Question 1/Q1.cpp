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

std::string onlyLowerCase(std::string entry)
{
    for (int i = 0; i < entry.size(); i++)
    {
        if (!islower(entry[i])) {entry.erase(i,1); i--;}
    }
    return entry;
}

int main()
{
    std::ifstream in_file("input.txt");
    std::ofstream out_file("output.txt");
    std::string text_from_file, line;

    // Prompt
    std::cout
    << "This program will take a text input and remove all but the lower cased letters, including spaces." << std::endl 
    << "Please, ensure that the text file is named 'input.txt'." << std::endl << std::endl;

    // If both files are available...
    if(in_file && out_file)
    {
        // Copy line by line
        while(getline(in_file,line))
        {
            out_file << onlyLowerCase(line) << '\n';    // while only taking the lower case letters
        }

        // Give completion message
        std::cout << "Copy Finished \n";

        // Close the Original and Copy files
        in_file.close();
        out_file.close();
    }

    else // If something went wrong
    {
        // Give error message
        printf("Cannot read File");
    }
}