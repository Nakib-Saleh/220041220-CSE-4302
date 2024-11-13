#include <bits/stdc++.h>
using namespace std;

class Circle{
private:
    float x,y;
    float radius;

public:
    Circle(float x_val,float y_val, float radius_val){
    x= x_val;
    y= y_val;
    radius=radius_val;  // radius neg check;
}
    Circle():x(0), y(0), radius(0){}

    ~Circle(){
        cout<<"Destructor Called"<<endl;
    };
    void display(){
        cout<<"Absicca = "<<x<<endl;
        cout<<"Ordinate = "<<y<<endl;
        cout<<"Radius = "<<radius<<endl;
    }
    float getArea(){
        float area =M_PI *(radius*radius);
        return area;
    }
    float getCircumference(){
        float cir= 2*M_PI*radius;
        return cir;
    }
    void scale(float fac){
        radius= radius*fac; // cannot be neg factor;
    }

    friend void operator ++( Circle &c);  
    friend void operator ++( Circle &c,int);  

    friend void operator -- ( Circle &c);
    friend void operator -- ( Circle &c,int);

    friend bool operator == ( const Circle &c1, const Circle &c2);

    friend void sortByArea (Circle *c);

};

void operator ++( Circle &c){
    c.radius = c.radius+1;
}
void operator ++( Circle &c,int){
    c.radius = c.radius+1;
}

void operator -- ( Circle &c){
    float curr= c.radius-1;
    if(curr < 0){
        cout<<"Neg radius not possible"<<endl;
    }
    else{
        c.radius= c.radius-1;
    }
    
}

void operator -- ( Circle &c,int){
    float curr= c.radius-1;
    if(curr < 0){
        cout<<"Neg radius not possible"<<endl;
    }
    else{
        c.radius= c.radius-1;
    }
}

bool operator == ( const Circle &c1, const Circle &c2){
    return ((c1.radius == c2.radius)&& (c1.x==c2.x) &&(c1.y==c2.y));
}

void sortByArea (Circle *c){
    for(int i=0; i<9;i++){
        for(int j=i+1; j<10; j++){
            if((c[i].getArea()) > c[j].getArea()){
                Circle temp = c[j];
                c[j]=c[i];
                c[i] = temp;
            }
        }
    }
}

int main(){
    Circle c[10];
    sortByArea(c);
}