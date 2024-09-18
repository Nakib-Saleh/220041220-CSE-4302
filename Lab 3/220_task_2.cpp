#include <bits/stdc++.h>
using namespace std;

class RationalNumber
{
    int _numerator, _denominator;

public:
    void assign(int numerator, int denominator)
    {

        if (denominator == 0)
        {
            cout << "You can not assign 0 as denominator" << endl;
        }
        else
        {
            _denominator = denominator;
            _numerator = numerator;
        }
    }

    float convert()
    {
        return ((float)_numerator / _denominator);
    }

    void invert()
    {
        int temp = _numerator;
        if (temp == 0)
        {
            cout << "You can not assign 0 as denominator.Inversion Failed" << endl;
        }
        else
        {
            _numerator = _denominator;
            _denominator = temp;
        }
    }

    void print()
    {
        cout << "The Rational Number is " << _numerator << "/" << _denominator << endl;
    }
};

int main()
{
    RationalNumber r1;
    r1.assign(3, 0);

    r1.assign(3, 2);
    cout << r1.convert() << endl;

    r1.assign(0, 2);
    r1.print();
    r1.invert();
    r1.print();
}