#include<bits/stdc++.h>
using namespace std ; 
#include "header.h"

Student:: Student(): gpa(0){}

void Student :: setname(string str){
    name= str;
}
string Student :: getname(){
    return name;
}

void Student :: setdepartment(string str){
    department= str;
}
string Student :: getdepartment(){
    return department;
}

void Student :: setprogram(string str){
    program= str;
}
string Student :: getprogram(){
    return program;
}

void Student :: setsection(string str){
    section= str;
}
string Student :: getsection(){
    return section;
}

void Student :: setaddress(string str){
    address= str;
}
string Student :: getaddress(){
    return address;
}

void Student ::  setadmission_year(int n){
    admission_year = n;
}
int Student :: getadmission_year(){
    return admission_year;
}

void Student ::  setid(int n){
    id = n;
}
int Student :: getid(){
    return id;
}

void Student ::  setgpa(float n){
    gpa = n;
}
float Student :: getgpa(){
    return gpa;
}

void Student:: calculate_gpa_input(){
    cout<<"Number of course ? :";
        int n;
        cin>>n;

        int temp =n;

        float cgpa=0;
        float total_gpa=0;

        while(n--){
        
            //Quiz
            float totalQuiz=0;
            cout<<"Mark of Quizes: ";
            float x,min=INT_MAX;
            
            for(int i=0; i<4; i++){
                cin>>x;
                if(x<min) min=x;
                totalQuiz+=x;
            }
            totalQuiz-=min;

            cout<<"Mark of Mid: ";
            float mid;
            cin>>mid;

            cout<<"Mark of Final: ";
            float final;
            cin>>final;

            cout<<"Mark of attendence: ";
            float attendence;
            cin>>attendence;
            
            float total;
            total=(mid+final+attendence+totalQuiz);
            
            float gpa=0;

            if(total>=80) gpa= 4;
            else if(total>=70) gpa= 3.5;
            else if(total>=60) gpa= 3;
            else if(total>=50) gpa= 2.5;
            else if(total>=40) gpa= 2;
            else  gpa= 0;

            total_gpa+=gpa;

        }
        cgpa= total_gpa/temp;
        setgpa(cgpa);
}

void Student :: calculate_gpa(){
    float total=0;
    for(int i=0; i<marks.size(); i++){
        total+=marks[i];
    }
    setgpa(total/marks.size());
}

void Student :: setmarks(float m){
    marks.push_back(m);
}

