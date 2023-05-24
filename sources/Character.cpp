/**
 * @brief implementations for character object
 * @authors Lior Vinman
 */

#include <iostream>

using namespace std;

#include "Character.hpp"

namespace ariel
{
        Character::Character() : _name("default"), _healthPoints(100), _location(Point{}), _team(false) {}

        Character::Character(string name, Point p, int hitPoints) : _name(name), _healthPoints(hitPoints), _location(p), _team(false) {}

        bool Character::isAlive()
        {
            return (this->_healthPoints > 0);
        }

        double Character::distance(Character *c)
        {
            return (this->_location.distance(c->_location));
        }

        void Character::hit(int dmg)
        {
            if(dmg < 0)
            {
                throw invalid_argument("Cannot perform negative damage!!!");
            }

            this->_healthPoints -= dmg;
        }

        string Character::getName()
        {
            return (this->_name);
        }

        Point Character::getLocation()
        {
            return (this->_location);
        }

        bool Character::getTeam()
        {
            return (this->_team);
        }

        int Character::getType()
        {
            return (this->_type);
        }

        int Character::getHP()
        {
            return (this->_healthPoints);
        }

        void Character::setLocation(Point &p)
        {
            this->_location = p;
        }

        void Character::setTeam(bool t)
        {
            this->_team = t;
        }

        void Character::setType(int type)
        {
            this->_type = type;
        }

        string Character::print()
        {
            return "";
        }
}
