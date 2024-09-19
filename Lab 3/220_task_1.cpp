#include <bits/stdc++.h>
using namespace std;

class Counter
{
private:
    int count;
    int incrementAmount;

public:
    Counter(){
        count=0;
        incrementAmount=0;
    }
    void setIncrementStep(int n)
    {
        incrementAmount = n;
    }
    int getCount()
    {
        return count;
    }

    void increment()
    {
        count += incrementAmount;
    }
    void resetCount()
    {
        count = 0;
    }
};

int main()
{
    int incri = 4;

    Counter c1;
    cout << c1.getCount() << endl;

    c1.increment();
    cout << c1.getCount() << endl;

    c1.setIncrementStep(incri);
    c1.increment();
    cout << c1.getCount() << endl;

    c1.resetCount();
    cout << c1.getCount() << endl;
}