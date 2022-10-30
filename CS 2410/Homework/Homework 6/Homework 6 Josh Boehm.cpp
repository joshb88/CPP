/*
Joshua Boehm
26 October 2022
CS 2410
Program 6

Use Program 5 and 
Now in a particular factory , a team leader is an hourly paid production worker who leas a small team.  
In addition to hourly pay, team leaders earn a fixed  monthly  bonus.  
Team leaders are required to attend a minimum number of hours of training per year.  
Design a TeamLeader class that extends   ProductionWorker class  you designed in part 1 of this assignment.  
 
The TeamLeader  class should have:

+ member variable for the monthly bonus amount,
+ the required number of training hours, 
+ and the number of training hours that the team leader has attended.

Write one or more constructors and the appropriate accessor and mutator functions for the class.  
Demonstrate the class by writing a program that uses a TeamLeader object.
*/

#include <iostream>
#include <string>

using namespace std;

//Employee.h
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

//TeamLeader.h
class TeamLeader : public ProductionWorker
{
public:
    TeamLeader(string name, int empNo, string hireDate, int shift, double payRate, double monthlyBonus, double hoursRequired, double hoursAttended);
    TeamLeader();
    double getMonthlyBonusAmount() const;
    double getTrainingHoursRequired() const;
    double getTrainingHoursAttended() const;
    void setMonthlyBonusAmount(double monthlyBonus);
    void setTrainingHoursRequired(double hoursRequired);
    void setTrainingHoursAttended(double hoursAttended);
    ~TeamLeader();
private:
    double member_MonthyBonusAmount;
    double member_TrainingHoursRequired;
    double member_TrainingHoursAttended;
};

//TeamLeader.cpp
TeamLeader::TeamLeader(string name, int empNo, string hireDate, int shift, double payRate, double monthlyBonus, double hoursRequired, double hoursAttended):ProductionWorker(name, empNo, hireDate,shift, payRate)
{
    member_MonthyBonusAmount = monthlyBonus;
    member_TrainingHoursRequired = hoursRequired;
    member_TrainingHoursAttended = hoursAttended;
}

TeamLeader::TeamLeader() 
{  
    member_MonthyBonusAmount = 0; 
    member_TrainingHoursAttended = 0; 
    member_TrainingHoursRequired = 0; 
}

double TeamLeader::getMonthlyBonusAmount() const
{
    return member_MonthyBonusAmount;
}

double TeamLeader::getTrainingHoursRequired() const
{
    return member_TrainingHoursRequired;
}

double TeamLeader::getTrainingHoursAttended() const
{
    return member_TrainingHoursAttended;
}

void TeamLeader::setMonthlyBonusAmount(double monthlyBonus)
{
    member_MonthyBonusAmount = monthlyBonus;
}

void TeamLeader::setTrainingHoursRequired(double hoursRequired)
{
    member_TrainingHoursRequired = hoursRequired;
}

void TeamLeader::setTrainingHoursAttended(double hoursAttended)
{
    member_TrainingHoursAttended = hoursAttended;
}
TeamLeader::~TeamLeader()
{
}
int main()
{
    TeamLeader test_leader("Max", 4321, "14/08/2004", 2, 34.75, 500, 50, 65);
    int MonthlyHoursWorked = 240;

    cout << "\n Employee Name : " << test_leader.getName()
        << "\n Employee No : " << test_leader.getEmpNo()
        << "\n Hire Date : " << test_leader.getHireDate()
        << "\n Shift : " << test_leader.getShift()
        << "\n Hourly Pay Rate : " << test_leader.getPayRate()
        << "\n Total Pay for " << MonthlyHoursWorked << " Hours Worked : " << test_leader.getPayRate() * MonthlyHoursWorked
        << "\n Monthly Bonus: " << test_leader.getMonthlyBonusAmount()
        << "\n Yearly Hours of Training Required: " << test_leader.getTrainingHoursRequired()
        << "\n Yearly Hours of Training Attended: " << test_leader.getTrainingHoursAttended();

    return 0;
}