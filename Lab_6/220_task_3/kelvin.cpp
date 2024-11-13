#include <iostream>
#include "celsius.h"
#include "farenheit.h"
#include "kelvin.h"

using namespace std;

Kelvin :: Kelvin(float val=0){
    assign(val);
}
void Kelvin :: assign(float val){
    if(val<- 273.15){
        cout<<"Cant set temp lower than absolute temp";
    }
    else{
        temp=val;
    }
}

void Kelvin :: display(){
    cout<<"The temperature is " <<temp<< " Kelvin"<<endl;
}

Kelvin:: operator Farenheit() const{
    return ((temp-273.15)*((9/5)+32));
}

Kelvin:: operator Celsius() const{
    return (temp-273.15);
}
