#include <iostream>
#include <string>
#include <math.h>

using namespace std; 

#pragma once


class Line {
private:

    double x1, y1, x2, y2;

public:

    Line();

    Line(double x__2, double y__2);

    Line(double x_1, double y_1, double x_2, double y_2);

    double getX1();
    double getY1();
    double getX2();
    double getY2();

    void count_lenght();

    Line& operator ++();

    bool operator||(const Line& other);

    void info();

};

Line create_two_points();
Line create_one_point();
Line create_vector();
