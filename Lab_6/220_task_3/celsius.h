#ifndef CELSIUS_H
#define CELSIUS_H

#include <bits/stdc++.h>
using namespace std;

class Farenheit;
class Kelvin;

class Celsius{
  float temp;
public:
  Celsius(float val=0);
  void assign(float val);
  void display();

  operator Farenheit() const;
  operator Kelvin() const;

};

#endif