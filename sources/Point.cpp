/**
 * @brief implementations for point object
 * @authors Lior Vinman
 */

#include <iostream>
#include <cmath>
using namespace std;

#include "Point.hpp"
namespace ariel
{
    Point::Point() : _x(0), _y(0) {}

    Point::Point(double x, double y) : _x(x), _y(y) {}

    void Point::Print()
    {
        cout << "(" << this->_x << "," << this->_y << ")" << endl;
    }

    double Point::getX()
    {
        return (this->_x);
    }

    double Point::getY()
    {
        return (this->_y);
    }

    Point Point::moveTowards(const Point &current, const Point &other, double dist)
    {
        double newX = 0.0, newY = 0.0, fac = 0.0, newX_val = 0.0, newY_val = 0.0;

        if(dist < 0)
        {
            throw invalid_argument("Cannot move negative distance!!!");
        }

        double distance = current.distance(other);
        if (distance <= dist)
        {
            return other;
        }

        newX = other._x - current._x;
        newY = other._y - current._y;

        fac = (dist / distance);

        newX_val = current._x + newX * fac;
        newY_val = current._y + newY * fac;

        return Point(newX_val, newY_val);
    }

    double Point::distance(const Point &p) const
    {
        return sqrt(pow(this->_x - p._x, 2) + pow(this->_y - p._y, 2));
    }
}