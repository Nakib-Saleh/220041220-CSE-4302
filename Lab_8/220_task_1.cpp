#include <bits/stdc++.h>
using namespace std;

class CurrentAccount;
class SavingsAccount;

class Account
{
protected:
    string accountNo;
    string accountName;
    float balance;

public:
    Account(string name, float bal) : accountName(name), balance(bal) {}

    void getInfo()
    {
        cout << " Account no: " << accountNo << endl;
        cout << " Account name: " << accountName << endl;
        cout << " Balance: " << balance << endl;
    }

    void setInfo(string accountN, float balac)
    {
        accountName = accountN;
        balance = balac;
    }
};

class CurrentAccount : public Account
{
protected:
    const static int serviceCharge;
    const static int accountPrefix;
    static int nextAccount;

public:
    CurrentAccount(string name, float bal) : Account(name, bal)
    {
        accountNo = nextAccountNo();
    }

    static string nextAccountNo()
    {
        return to_string(accountPrefix) + "-" + to_string(nextAccount++);
    }
};

const int CurrentAccount ::serviceCharge = 100;
const int CurrentAccount::accountPrefix = 100;
int CurrentAccount::nextAccount = 0;

class SavingsAccount : public Account
{
protected:
    float interestRate;
    float MonthlyDepositeAmount;
    const static int accountPrefix;
    static int nextAccount;

public:
    SavingsAccount(string name, float bal, float interest, float depoAmount) : Account(name, bal), interestRate(interest), MonthlyDepositeAmount(depoAmount)
    {
        accountNo = nextAccountNo();
    }

    static string nextAccountNo()
    {
        return to_string(accountPrefix) + "-" + to_string(nextAccount++);
    }
};

const int SavingsAccount::accountPrefix = 200;
int SavingsAccount::nextAccount = 0;

class MonthlyDepositeScheme : public Account
{
protected:
    float interestRate;
    float MonthlyDepositeAmount;
    const static int accountPrefix;
    static int nextAccount;

public:
    MonthlyDepositeScheme(string name, float bal, float interest, float depoAmount) : Account(name, bal), interestRate(interest), MonthlyDepositeAmount(depoAmount)
    {
        accountNo = nextAccountNo();
    }

    static string nextAccountNo()
    {
        return to_string(accountPrefix) + "-" + to_string(nextAccount++);
    }
};

const int MonthlyDepositeScheme::accountPrefix = 300;
int MonthlyDepositeScheme::nextAccount = 0;

class LoanAccount : public Account
{
protected:
    float interestRate;
    float MonthlyDepositeAmount;
    const static int accountPrefix;
    static int nextAccount;

public:
    LoanAccount(string name, float bal, float interest, float depoAmount) : Account(name, bal), interestRate(interest), MonthlyDepositeAmount(depoAmount)
    {
        accountNo = nextAccountNo();
    }

    static string nextAccountNo()
    {
        return to_string(accountPrefix) + "-" + to_string(nextAccount++);
    }
};

const int LoanAccount::accountPrefix = 900;
int LoanAccount::nextAccount = 0;

class TwoYearMDS : public MonthlyDepositeScheme
{
    int maximuminterest;

public:
    TwoYearMDS(string name, float bal, float interest, float depoAmount, int maxiinter) :
     MonthlyDepositeScheme(name, bal, interest, depoAmount), maximuminterest(maxiinter) {}
};

class FiveYearMDS : public MonthlyDepositeScheme
{
    int maximuminterest;

public:
    FiveYearMDS(string name, float bal, float interest, float depoAmount, int maxiinter) :
     MonthlyDepositeScheme(name, bal, interest, depoAmount), maximuminterest(maxiinter) {}
};

class initialDepositeMDS : public MonthlyDepositeScheme
{
    int maximuminterest;
    int initialDepositeAmount;

public:
    initialDepositeMDS(string name, float bal, float interest, float depoAmount, int maxiinter, int initialDepo) : 
    MonthlyDepositeScheme(name, bal, interest, depoAmount), maximuminterest(maxiinter), initialDepositeAmount(initialDepo) {}
};

int main(){
    
}