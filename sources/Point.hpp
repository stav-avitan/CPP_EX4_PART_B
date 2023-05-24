#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <float.h>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        static Point moveTowards(const Point &, const Point &, const double) ;
        Point();
        Point(double, double);
        virtual string print();
        double distance(Point) const;
        double getY() const;
        double getX() const;
        
        
    };
}
