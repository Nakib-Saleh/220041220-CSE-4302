#include<bits/stdc++.h>
#include <cstdlib> 
#include <ctime>   

using namespace std  ;
#include "header.h"

float randomFloat(float min, float max) {
    if (min > max) {
        std::swap(min, max); 
    }


    float randomFraction = static_cast<float>(rand()) / RAND_MAX;

    return min + randomFraction * (max - min);
}
int randomInt(int min, int max) {

    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    return rand() % (max - min + 1) + min;

}

string generateRandomString(int length) {
    string randomString;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1; // Exclude null character

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        randomString += alphabet[rand() % alphabetSize];
    }

    return randomString;
}


int generateID(){
    int id=0;
    id+=randomInt(20,24);
    id*100000;

    id+=randomInt(1,6);
    id*10;

    id+=randomInt(1,2);
    id*10;

    id+=randomInt(1,3);
    id*100;

    id+=randomInt(1,70);

    return id;
}

string randname(int n){
    string name="";

    while(n--){
        name+=generateRandomString(10);
        name+=" ";
    }

    return name;

}



void EditInformationByKeyboard(Student s){
    string str;

    cout<<"Enter Name: ";
    getline(cin,str);
    s.setname(str);

    cout<<"Enter department: ";
    getline(cin,str);
    s.setdepartment(str);

    cout<<"Enter program: ";
    getline(cin,str);
    s.setprogram(str);

    cout<<"Enter section: ";
    getline(cin,str);
    s.setsection(str);

    cout<<"Enter address: ";
    getline(cin,str);
    s.setaddress(str);

    cout<<"Enter year: ";
    int year;
    cin>>year;
    s.setadmission_year(year); 
}

void generateInformaiotnRandom(Student s){
    int n=4;
    while(n--){
        s.setmarks(randomFloat(0,100));
    }
    s.setname(randname(2));

    s.setadmission_year(randomInt(2020,2023));
    s.setaddress(randname(5));
    s.setid(generateID());
}


int main(){
}