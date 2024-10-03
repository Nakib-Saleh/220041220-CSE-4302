#include<bits/stdc++.h>
using namespace std ; 
#include "header.h"

void Employee:: setName(string str){
    if(str.length()<=2){
        name= "John Doe";
        return;
    }
    name=str;
}

void Employee:: setDate_of_birth(string str){
    int age = 2024- stoi(str.substr(6,4));
    if(age<=18){
        date_of_birth = str;
        return;
    }
    else{
        date_of_birth = "01-01-2002";
    }
}

void Employee:: setSalary(int val){
    
}