#include <iostream>
#include "celsius.h"
#include "farenheit.h"
#include "kelvin.h"

using namespace std;

Farenheit :: Farenheit(float val=0){
    assign(val);
}
void Farenheit :: assign(float val){
    if(val<- 459.60){
        cout<<"Cant set temp lower than absolute temp";
    }
    else{
        temp=val;
    }
}

void Farenheit :: display(){
    cout<<"The temperature is " <<temp<< " Farenheit"<<endl;
}


Farenheit :: operator Celsius() const{
    return (temp/((9/5)+32));
}

Farenheit :: operator Kelvin() const{
    return (temp/((9/5)+32))+237.15;
}
