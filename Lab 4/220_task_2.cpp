#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    int account_number;
    string account_holder_name;
    string account_type;
    float current_balance;
    const float min_balance;

public:
    static int account_present;
    static int account_created;
    static float tax;

    BankAccount(int ac_no, string ac_name, string ac_type, float curr, int min) : min_balance(min)
    {
        account_number = ac_no;
        account_holder_name = ac_name;
        account_type = ac_type;
        current_balance = curr;
        account_present++;
        account_created++;
    }
    ~BankAccount(){
        cout<<"Account of "<<account_holder_name;
        cout<<" with account no "<<account_number;
        cout<<" is destroyed with a balance BDT "<<current_balance<<endl;
        account_present--;
    }
    void showBalance()
    {
        cout << "Current Balance: " << current_balance << endl;
    }
    void deposit(float value)
    {
        current_balance += value;
    }
    void withdrawal(float value)
    {
        if ((current_balance - value) <= min_balance)
        {
            cout << "Not Enough Balance" << endl;
        }
        else
        {
            current_balance -= value;
        }
    }

    void giveInterest(float value = 3)
    {   value= value/100;
        float curr_interest = current_balance * value;
        tax += curr_interest * 0.1;
        current_balance += (curr_interest - curr_interest * 0.1);
    }
    float getBalance() const{
        return current_balance;
    }
};

int BankAccount::account_present = 0;
int BankAccount::account_created = 0;
float BankAccount::tax = 0;

void display_stat()
{
    cout << "accounts present: " << BankAccount::account_present << endl;
    cout << "account created: " << BankAccount::account_created << endl;
    cout << "amount of source tax collected: " << BankAccount::tax << endl;
}
BankAccount Larger(const BankAccount A, const BankAccount B){
    if(A.getBalance()>B.getBalance()){
        return A;
    }
    else{
        return B;
    }
}

int main(){
    BankAccount q1(123,"nakib","savings",50000,100);
    BankAccount q2(1344,"nak","savings",40000,100);
    BankAccount q3(123,"naib","savings",70000,100);

    q1.showBalance();

    q1.deposit(1990.220);
    q1.showBalance();

    q1.withdrawal(1990.220);
    q1.showBalance();

    q1.giveInterest(10);
    q1.showBalance();

    display_stat();

}