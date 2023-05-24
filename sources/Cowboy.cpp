/**
 * @brief implementations for cowboy object
 * @authors Lior Vinman
 */


#include <iostream>
using namespace std;

#include "Cowboy.hpp"
namespace ariel
{
    Cowboy::Cowboy(std::string name, Point location) : Character(name, location, 110) , _bullets(6)
    {
        this->setType(1);
    }

    void Cowboy::shoot(Character* other)
    {
        if(!this->_bullets) // dont have bullets
        {
            return;
        }
        if(this->getHP() <= 0) // dead case
        {
            throw runtime_error("Cant shoot if you are dead!!!");
        }
        if(other == this) // shoot yourself
        {
            throw runtime_error("Why shoot yourself??");
        }
        if(!other->isAlive()) // dead target
        {
            throw runtime_error("Target is aleady dead!!!");
        }
        other->hit(10);
        this->_bullets -= 1;
    }

    bool Cowboy::hasboolets()
    {
        return (this->_bullets > 0);
    }
    
    void Cowboy::reload()
    {
        if(!this->isAlive())
        {
            throw runtime_error("You are dead!!!");
        }
        this->_bullets = 6;
    }

    string Cowboy::print()
    {
        string p = "";

        p += "Type: 'C', Name: '" + this->getName() + "', Status: '";
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
