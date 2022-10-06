#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

/* Josh Boehm
1 April, 2022
CS1411 */


using namespace std;

// Several constants use throughout; names are self explanitory.
const int NUM_EMP = 2;                  // Changing this constant (to something small) will make testing the program much less tedious.
const float TAX_BREAKPOINT = 2500;      // Income threshold where the tax rate changes
const float HIGH_RATE = .33;
const float LOW_RATE = .24;
const string ORIGINAL = "Original.txt";
const string COPY = "Copy.txt";
const string SECTION_BREAK = "\n--------------------------------------------------\n--------------------------------------------------\n";

// A structure to handle each employee's information as it's utilized
struct employee
{
    string name;
    int id;
    float hrs, rate, gross, tax, net; 
};

int main(){

    // Used to read and write data from each file
    ofstream outfile;
    ifstream infile;

    // Variables to temporarily hold data entries until they can be stored in the struct
    string line, name;
    int i = 0;
    float id;
    float hrs,rate,gross,tax,net;
    
    //Instance of a vector for my struct (so that I can make multiple instances of the same emp)
    vector<employee>emp;

    // Ensure the size is appropriate, based on the desired employee records to enter
    emp.resize(NUM_EMP);

    // Opens the file prepared to write
    outfile.open(ORIGINAL.c_str(), ios::out);

    cout << SECTION_BREAK;

    // Take each variable of info related to the employee struct
    for (int i = 0; i < NUM_EMP; i++)  // Iterates for the value of the NUM_EXP constant
    {
        cout << '\n' << "Employee No. " << i+1 << endl;
        cout << "Name: ";
        cin >> emp[i].name;

        cout << "ID Number: ";
        cin >> emp[i].id;
        while (emp[i].id < 0)  // Imput verification
        {
            cout << "Enter a positive ID number"<<endl;
            cin >> emp[i].id;
        }

        cout << "Weekly Hours: ";
        cin >> emp[i].hrs;
        while (!(emp[i].hrs > 0 && emp[i].hrs < 80))  // Imput verification
        {
            cout << "Enter a positive value less than 80"<<endl;
            cin >> emp[i].hrs;
        }

        cout << "Hourly Rate: ";
        cin >> emp[i].rate;
        while (!(emp[i].rate > 0 && emp[i].rate < 200))  // Imput verification
        {
            cout << "Enter a positive value less than 200"<<endl;
            cin >> emp[i].rate;
        cout << endl;
        }

        // Calculation Subsection
        emp[i].gross = emp[i].hrs * emp[i].rate;

        // Decision structure for tax rates
        if (emp[i].gross > TAX_BREAKPOINT)
        { 
            emp[i].tax = emp[i].gross * HIGH_RATE;
        }
        else
        {
            emp[i].tax = emp[i].gross * LOW_RATE;
        }
        emp[i].net = emp[i].gross - emp[i].tax;

        // Writing read data to the Original document
        outfile << emp[i].name << '\t' << 
                    emp[i].id << '\t' << 
                    emp[i].hrs << '\t' << 
                    emp[i].rate << '\t' <<
                    emp[i].gross << '\t' <<
                    emp[i].tax << '\t' << 
                    emp[i].net << '\n';
    
    }
    outfile.close();  // Closes the file.

    // Writing original phase ends; Copying phase begins
    cout << SECTION_BREAK;


    // Opens Original to be read
    infile.open(ORIGINAL.c_str(), ios::in);
    

    // Ensures the Original file is available to be copied from.
    if(infile.fail())
    {
        cout<<"Unable to open file" << endl << "Restart Program" << endl;
        return 0;
    }

    // Opens Copy to be written to
    outfile.open(COPY.c_str(), ios::out);

    //Ensures the Copy file is available to be copied to
    if(outfile.fail())
    {
        cout<<"Unable to open file" << endl << "Restart Program" << endl;
        return 0;
    }
    
    // If both are available...
    if(infile && outfile)
    {
        
        // Copy line by line
        while(getline(infile,line))
        {
            outfile << line << '\n';
        }

        // Give completion message
        cout << "Copy Finished \n";

        // Close the Original and Copy files
        infile.close();
        outfile.close();
    }

    else // If something went wrong
    {
        // Give error message
        printf("Cannot read File");
    }

    // Copy phase ends; Display phase begins
    cout << SECTION_BREAK;

    // Open Copy file as read
    infile.open(COPY.c_str(), ios::in);


    // For each line, read and re-assign to the struct
    while (infile >> name >> id >> hrs >> rate >> gross >> tax >> net)
    {
        emp[i].name = name;
        emp[i].id = id;
        emp[i].hrs = hrs;
        emp[i].rate = rate;
        emp[i].gross = gross;
        emp[i].tax = tax;
        emp[i].net = net;
        i++;
    }
   
    // For each employee, dispaly the data stored from the read of Copy
    for (int i = 0; i < NUM_EMP; i++)
    {
        cout << "Employee No. " << i+1 << endl <<
                "Name: " << emp[i].name << "\n" << 
                "ID: " << emp[i].id << '\n' << 
                "Hours Worked: " << emp[i].hrs << '\n' << 
                "Hourly Rate: " << emp[i].rate << '\n' << 
                "Gross Pay: " << emp[i].gross << '\n' << 
                "Tax: " << emp[i].tax << '\n' << 
                "Net Pay: " << emp[i].net << endl << endl;
    }

    // Display phase ends
    cout << SECTION_BREAK;

    // Close Copy file
    infile.close();

    // End Program
    return 0;
}
