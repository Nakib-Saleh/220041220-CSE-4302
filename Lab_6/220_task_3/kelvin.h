#ifndef KELVIN_H
#define KELVIN_H

#include <bits/stdc++.h>
using namespace std;

class Celsius;
class Farenheit;


class Kelvin{
  float temp;
public:
  Kelvin(float val=0);
  void assign(float val);
  void display();

  operator Celsius() const;
  operator Farenheit() const;

};

#endif