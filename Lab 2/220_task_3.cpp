#include <bits/stdc++.h>
using namespace std;

typedef struct fraction{
    int numerator;
    int denominator;
}fraction;

int main(){
   fraction n1,n2,sum;
   char dummy='/';

   cout<<"Enter first fraction:";
   cin>>n1.numerator>>dummy>>n1.denominator;

   cout<<"Enter second fraction:";
   cin>>n2.numerator>>dummy>>n2.denominator;

   sum.numerator=(n1.numerator*n2.denominator + n1.denominator*n2.numerator);
   sum.denominator=(n1.denominator*n2.denominator);

   cout<<"Sum ="<<sum.numerator<<dummy<<sum.denominator;
}