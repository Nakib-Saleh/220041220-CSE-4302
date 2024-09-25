#include <bits/stdc++.h>
using namespace std;

class Trigonometry_Calculator
{
private:
    float curr_angle;

    void setAngle(float value){
        curr_angle=value;
    }

    float getAngle(){
        return (curr_angle)*(M_PI/180);
    }

public:
    Trigonometry_Calculator(){
        curr_angle=0;
    }
    
    Trigonometry_Calculator(float value){
        curr_angle=value;
    }
    float calculateSine(){
       return sin(getAngle()); 
    }
    float calculateCosine(){
       return cos(getAngle()); 
    }
    float calculateTangent(){
        if(curr_angle==90){
            cout<<"Undefined Value of tangent"<<endl;
        }
        else{
           return tan(getAngle()); 
        }
        return 0;
    }

    float calculateArcSine(){
        float rad= getAngle();
        cout<<"Angle in Radian: "<<rad<<endl;
        return asin(rad);
    }
    float calculateArcCosine(){
        return acos(getAngle());
    }
    float calculateArcTangent(){
        return atan(getAngle());
    }

    void calculateForAngle(float paramAngle){
        cout<<"Sine: "<< sin(paramAngle*(M_PI/180))<<endl;
        cout<<"Cos: "<< cos(paramAngle*(M_PI/180))<<endl;
        if(paramAngle==90){
           cout<<"Undefined Value of tangent"<<endl; 
        }
        else{
           cout<<"Tan: "<< tan(paramAngle*(M_PI/180))<<endl; 
        }
    }

    void clear(){
        curr_angle=0;
    }
    void display(){
        cout<<"Calculator display: "<<curr_angle<<endl;
    }
    ~Trigonometry_Calculator(){
        cout<<"current Value: "<<curr_angle<<endl;
        cout<<"Destructor of the Calculator object is called."<<endl;
    }

    

};

int main(){
    Trigonometry_Calculator t1(30);
    cout<<t1.calculateSine()<<endl;
    cout<<t1.calculateCosine()<<endl;
    cout<<t1.calculateTangent()<<endl;

    cout<<t1.calculateArcSine()<<endl;
    cout<<t1.calculateArcCosine()<<endl;
    cout<<t1.calculateArcTangent()<<endl;

    t1.display();

    t1.calculateForAngle(90);


}