/**
 * @brief implementations for ninja object
 * @authors Lior Vinman
 */


#include <iostream>
using namespace std;

#include "Ninja.hpp"
namespace ariel
{
    Ninja::Ninja() : Character() , _speed(0){this->setType(2);}

    Ninja::Ninja(string name, Point p, int speed , int hitpoints) : Character(name, p, hitpoints), _speed(speed) {this->setType(2);}

    void Ninja::move(Character *c)
    {
        Point nLoc;

        if (c == nullptr)
        {
            throw invalid_argument("Other not exists!!! (nullptr)");
        }
        else if (c == this)
        {
            throw invalid_argument("Already in destination!!!");
        }
        else if (!isAlive())
        {
            throw runtime_error("Got killed!!!");
        }

        nLoc = Point::moveTowards(getLocation(), c->getLocation(), _speed);
        setLocation(nLoc);
    }

    void Ninja::slash(Character *c)
    {
        if(this->getHP() <= 0)
        {
            throw runtime_error("Got killed!!!");

        }
        else if(this == c)
        {
            throw runtime_error("Want to slash yourself?!");
        }
        else if(!c->isAlive())
        {
            throw runtime_error("Target is killed!!!");
        }
        if(this->getLocation().distance(c->getLocation()) <= 1)
        {
            c->hit(40);
        }
    }

    string Ninja::print()
    {
        string p = "";

        p += "Type: 'N', Name: '" + this->getName() + "', Status: '";
        if(this->isAlive())
        {
            p += "Alive'";
        }
        else
        {
            p += "Dead'";
        }
        p += ", Location: '(" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")'";

        return p;
    }

}