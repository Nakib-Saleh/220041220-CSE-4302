#ifndef HEADER_H
#define HEADER_H

#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    string name;
    string date_of_birth;
    int salary;
public:
    void setName(string str);
    string getName();

    void setDate_of_birth(string str);
    string getDate_of_birth();

    void setSalary(int value);
    int getSalary();

};

#endif