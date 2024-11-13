#ifndef HEADER_H
#define HEADER_H

#include <bits/stdc++.h>
using namespace std;



class Coordinate{
private:
    float abscissa_x;
    float ordinate_y;
public:
    Coordinate();
    Coordinate(float x,float y);

    ~Coordinate();

    void display();
    float operator - (const Coordinate &c) const;

    float getDistance()const ;
    void move_x(float val);
    void move_y(float val);
    void move(float x_val, float y_val);

    bool operator < (const Coordinate & right)const;
    bool operator > (const Coordinate & right)const;
    bool operator <= (const Coordinate & right)const;
    bool operator >= (const Coordinate & right)const;
    bool operator == (const Coordinate & right)const;
    bool operator != (const Coordinate & right)const;

    friend void randomAssignment(Coordinate c[], int size);
    friend void highest(Coordinate c[], int size);
    friend void lowest(Coordinate c[], int size);

};

#endif