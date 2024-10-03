#ifndef HEADER_H
#define HEADER_H

#include <bits/stdc++.h>
using namespace std;

class Student{
private:
    string name;
    string department;
    string program;
    string section;
    int admission_year;
    string address;
    float gpa;
    int id;

    vector <float> marks;

public:
    Student();

    void setname(string str);
    string getname();

    void setdepartment(string str);
    string getdepartment();

    
    void setprogram(string str);
    string getprogram();

    void setsection(string str);
    string getsection();

    void setadmission_year(int n);
    int getadmission_year();

    void setid(int n);
    int getid();

    void setaddress(string str);
    string getaddress();

    void setgpa(float n);
    float getgpa();

    void calculate_gpa_input();
    void calculate_gpa();

    void setmarks(float m);
};

#endif