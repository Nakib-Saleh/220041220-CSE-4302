#include<bits/stdc++.h>
#include <cstdlib> 
#include <ctime>   

#include "celsius.h"
#include "farenheit.h"
#include "kelvin.h"

using namespace std  ;

int main(){
    Celsius c(0);
    Farenheit f(60);

    Farenheit f1= c;
    f1.display();
}
