#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const int NUM_EMP = 3;
const float TAX_BREAKPOINT = 2500;
const float HIGH_RATE = .33;
const float LOW_RATE = .24;
const string ORIGINAL = "Original.txt";
const string COPY = "Copy.txt";

struct employee
{
    string name;
    int id;
    float hrs, rate, gross, tax, net; 
};

int main(){

    ofstream outfile;
    ifstream infile;

    string line, name;
    int i = 0;

    vector<employee>emp;
    float id;
    float hrs,rate,gross,tax,net;

    infile.open(COPY.c_str(), ios::in);

    emp.resize(20);


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
    cout << "END OF RUN";
    return 0;
}
