#include<bits/stdc++.h>
using namespace std ; 
#include "header.h"

Coordinate:: Coordinate(){
    abscissa_x = 0;
    ordinate_y = 0;
}

Coordinate:: Coordinate(float x,float y): abscissa_x(x),ordinate_y(y){}

Coordinate:: ~Coordinate(){}

void Coordinate:: display(){
    cout<<"abscissa : "<<abscissa_x<<endl;
    cout<<"ordinate : "<<ordinate_y<<endl;
}

float Coordinate:: operator - (const Coordinate &c) const{
    float d= sqrt(pow((c.abscissa_x-abscissa_x),2) + pow((c.ordinate_y-ordinate_y),2));
    return d;
}

float Coordinate:: getDistance() const{
    float d= sqrt(pow((abscissa_x),2) + pow((ordinate_y),2));
    return d;
}

void Coordinate :: move_x(float val){
    abscissa_x+=val;
}

void Coordinate :: move_y(float val){
    ordinate_y+=val;
}
void Coordinate :: move(float x_val, float y_val){
    abscissa_x+=x_val;
    ordinate_y+=y_val;
}

bool Coordinate::operator < (const Coordinate &right) const {
    float lobj = getDistance();
    float robj = right.getDistance();
    return lobj < robj;
}
bool Coordinate::operator > (const Coordinate &right) const {
    float lobj = getDistance();
    float robj = right.getDistance();
    return lobj > robj;
}

bool Coordinate::operator <= (const Coordinate &right) const {
    float lobj = getDistance();
    float robj = right.getDistance();
    return lobj <= robj;
}

bool Coordinate::operator >= (const Coordinate &right) const {
    float lobj = getDistance();
    float robj = right.getDistance();
    return lobj >= robj;
}

bool Coordinate::operator == (const Coordinate &right) const {
    float lobj = getDistance();
    float robj = right.getDistance();
    return lobj == robj;
}

bool Coordinate::operator != (const Coordinate &right) const {
    float lobj = getDistance();
    float robj = right.getDistance();
    return lobj != robj;
}