/*
Josh Boehm
26 October 2022
CS 2410
Program 5

For this program we are using objects, class, Inheritance, Polymorphism, and virtual function.   
(Programming Challenge 1 & #3 Page 982-Chapter 15  E9)
Design a class named Employee.  The class should keep the following information:

* Employee name
* Employee number
* Hire date

Write one or more constructors, and the appropriate  accessors and mutator functions, for the class.  
Next write a class named   ProductionWorker that is derived from   Employee class. 
The   ProductionWorker  class should have member variables to hold the following information:

* Shift (an integer)
* Hourly pay rate (a double)

The workday is divided into two shifts: day and night.  
The shift variable hold an integer value representing the shift that the employee works.  
The day shift is shift 1, and the night shift is shift 2.  
Write one or more constructors, and the appropriates accessor  and mutator functions, 
for the class by witting a program that uses a   ProductionWorker object  
*/


//Employee.h
#include <iostream>
#include <string>

using namespace  std;

class Employee
{
public:
    Employee()
    {
        member_empNumber = 0;
    }
    
    Employee(string name,int empNo,string hireDate);
    string getName() const;
    string getHireDate() const;
    int getEmpNo() const;
    ~Employee();
    void setEmpNo(int number);
private:
    string member_empName;
    int member_empNumber;
    string member_HireDate;
};



//Employee.cpp
Employee::Employee(string name, int empNo, string hireDate):
member_empName(name),
member_empNumber(empNo),
member_HireDate(hireDate)
{
}

string Employee::getName() const
{
    return member_empName;
}
string Employee::getHireDate() const
{
    return member_HireDate;
}
int Employee::getEmpNo() const
{
    return member_empNumber;
}

Employee::~Employee()
{
}

void Employee::setEmpNo(int number)
{
    member_empNumber = number;
}



//ProductionWorker.h
class ProductionWorker : public Employee
{
public:
    ProductionWorker(string name, int empNo, string hireDate, int shift, double payRate);
    ProductionWorker();
    int getShift() const;
    double getPayRate() const;
    void setPayRate(double payRate);
    ~ProductionWorker();
private:
    int member_Shift;
    double member_HourlyPayRate;
};

//ProductionWorker.cpp

ProductionWorker::ProductionWorker(string name, int empNo, string hireDate,int shift, double payRate):Employee(name,empNo,hireDate),
member_HourlyPayRate(payRate)
{
    if(shift == 1 || shift == 2)
    {
        member_Shift = shift;
    }
    else
    {
        cout << "\n Shift is not proper ";
    }
}

ProductionWorker::ProductionWorker()
{
    member_Shift = 0;
}

int ProductionWorker::getShift() const
{
    return member_Shift;
}

double ProductionWorker::getPayRate() const
{
    return member_HourlyPayRate;
}

void ProductionWorker::setPayRate(double payRate)
{
    member_HourlyPayRate = payRate;
}

ProductionWorker::~ProductionWorker()
{
}

//Main.cpp


int main()
{
    ProductionWorker p("Mark", 1235, "03/02/2004", 1, 23.50);
    int MonthlyHoursWorked = 240;

    cout << "\n Employee Name : " << p.getName()
        << "\n Employee No : " << p.getEmpNo()
        << "\n Hire Date : " << p.getHireDate()
        << "\n Shift : " << p.getShift()
        << "\n Hourly Pay Rate : " << p.getPayRate()
        << "\n Total Pay for " << MonthlyHoursWorked << " Hours Worked : " << p.getPayRate() * MonthlyHoursWorked;

    return 0;
}