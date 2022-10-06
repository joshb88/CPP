#ifndef ACCOUNT
#define ACCOUNT

class Account
{
    private:
        int id; 
        double balance;
        double annualInterestRate;

    public:
        Account()
        {
            id = 0;
            balance = 0;
            annualInterestRate = 0;
        }
        Account(int setid, double setbal, double setrate)
            :id(setid), balance(setbal), annualInterestRate(setrate)
        {}
        int getId();
        double getBalance()                         const{       return balance;         }
        double getAnnualInteresteRate()             const{  return annualInterestRate;   }

        void setId(int setid)                            {         id = setid;           }
        void setBalance(double setbalance)               {      balance = setbalance;    }
        void setAnnualInterestRate(double setAIR)        {  annualInterestRate = setAIR; }
        void withdrawl(double amount)                    {      balance -= amount;       }
        void deposit(double amount)                      {      balance += amount;       }
        double getMonthlyInterestRate()                  { return annualInterestRate/12; }
};

#endif // ACCOUNT