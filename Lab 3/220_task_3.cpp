#include <bits/stdc++.h>
using namespace std;

class Medicine
{
    char trade_name[30];
    char generic_name[30];

    double unit_price = 0;
    double discount = 5;

public:
    void assignName(char name[], char genericName[])
    {
        strcpy(trade_name, name);
        strcpy(generic_name, genericName);
    }

    void assignPrice(double price)
    {
        if (price >= 0)
        {
            unit_price = price;
        }
        else
        {
            cout << "Assign price failed. Cannot enter negative number" << endl;
        }
    }

    void setDiscountPercent(double percent)
    {
        if (percent >= 0 && percent <= 30)
        {
            discount = percent;
        }
        else
        {
            cout << "Discount has to be within 0-30%" << endl;
        }
    }

    double getSellingPrice(int nos)
    {
        double sellingPrice = nos * (unit_price - ((unit_price * discount) / 100));
        return sellingPrice;
    }

    double getSellingPrice()
    {
        return (unit_price - ((unit_price * discount) / 100));
    }

    void display()
    {
        cout << "MRP. of ";
        cout << trade_name << " " << generic_name << " ";
        cout << "is BDT " << unit_price << " .";
        cout << "Current discount " << discount << "% .";
        cout << "Selling price BDT " << getSellingPrice() << "." << endl;
    }
};

int main()
{
    Medicine m1;
    char name[20], genericName[20];

    cin >> name >> genericName;
    m1.assignName(name, genericName);

    m1.assignPrice(-1);
    m1.setDiscountPercent(10);

    cout << m1.getSellingPrice(5) << endl;

    m1.display();
}