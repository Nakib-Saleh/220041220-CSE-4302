#include<bits/stdc++.h>
#include <cstdlib> 
#include <ctime>   

using namespace std  ;
#include "header.h"

float randomF(float min=-100, float max=100) {
    if (min > max) {
        std::swap(min, max); 
    }


    float randomFraction = static_cast<float>(rand()) / RAND_MAX;

    return min + randomFraction * (max - min);
}


void randomAssignment(Coordinate c[], int size){
    for(int i=0; i<size; i++){
        c[i].abscissa_x= randomF();
        c[i].ordinate_y =randomF();
    }
}
void highest(Coordinate c[], int size){
    float max_dis=INT_MIN;
    Coordinate temp;

    for(int i=0; i<size; i++){
        if(c[i].getDistance()>max_dis){
            temp=c[i];
        }
    }
    temp.display();
}

void lowest(Coordinate c[], int size){
    float min_dis=INT_MAX;
    Coordinate temp;

    for(int i=0; i<size; i++){
        if(c[i].getDistance()>min_dis){
            temp=c[i];
        }
    }
    temp.display();
}


int main(){
    /* Coordinate c1, c2(1,1);
    c1.display();
    c2.display();

    float d= c1-c2;
    cout<<d<<endl;
    cout<<c2.getDistance()<<endl;

    cout<< (c1==c2)<<endl; */

    Coordinate coord[10];
    randomAssignment(coord,10);
    Coordinate c1, c2;
    highest(coord,10);
    lowest(coord,10);
  
    
}
