#include <iostream>
#include "celsius.h"
#include "farenheit.h"
#include "kelvin.h"

using namespace std;

Celsius :: Celsius(float val=0){
    assign(val);
}
void Celsius :: assign(float val){
    if(val<- 273.15){
        cout<<"Cant set temp lower than absolute temp";
    }
    else{
        temp=val;
    }
}

void Celsius :: display(){
    cout<<"The temperature is " <<temp<< " Celsius"<<endl;
}

Celsius:: operator Farenheit() const{
    return (temp*((9/5)+32));
}

Celsius:: operator Kelvin() const{
    return (temp+273.15);
}



