#include <bits/stdc++.h>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive,researcher };

int main(){
    etype x;
    char ch;
    cout<<"Enter input:";
    cin>> ch;

    switch (ch)
    {
    case 'l':
        (x =laborer);
        break;  
    case 's':
        (x =secretary);
        break; 
    case 'm':
        (x =manager);
        break; 
    case 'a':
        (x =accountant);
        break; 
    case 'e':
        (x =executive);
        break; 
    case 'r':
        (x =researcher);
        break; 
    
    default:
        cout<<"Not Found"<<endl;
        break;
    }

    cout<<"Employee type is:";
    switch (x)
    {
    case 0:
        cout<<"laborer";
        break;  
    case 1:
        cout<<"secretary";
        break; 
    case 2:
        cout<<"manager";
        break; 
    case 3:
        cout<<"accountant";
        break; 
    case 4:
        cout<<"executive";
        break; 
    case 5:
        cout<<"researcher";
        break;
    
    default:
        cout<<"Not Found"<<endl;
        break;
    }
}