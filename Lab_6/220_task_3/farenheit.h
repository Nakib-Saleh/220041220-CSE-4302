#ifndef FAREN_H
#define FAREN_H

#include <bits/stdc++.h>
using namespace std;

class Celsius;
class Kelvin;

class Farenheit{
  float temp;
public:
  Farenheit(float val=0);
  void assign(float val);
  void display();

  operator Celsius() const;
  operator Kelvin() const;

};

#endif