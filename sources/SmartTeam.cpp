/**
 * @brief implementations for smart-team object
 * @authors Lior Vinman
 */

#include <iostream>
using namespace std;

#include "SmartTeam.hpp"
namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    Character* SmartTeam::ninja_victim(Ninja* ninja, Team* other)
    {
        double max = __DBL_MAX__;

        size_t i = 0;

        for (i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive())
            {
                if (other->getTeam().at(i)->distance(ninja) < max)
                {
                    max = other->getTeam().at(i)->distance(this->getLeader());
                }
            }
        }
        for (i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive())
            {
                if (other->getTeam().at(i)->distance(ninja) == max)
                {
                    return other->getTeam().at(i);
                }
            }
        }
        
        return nullptr;
    }
    Character* SmartTeam::cowboy_victim(Team* other)
    {
        int min_hp = 150;

        size_t i = 0;

        for (i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive())
            {
                if (other->getTeam().at(i)->getHP() < min_hp)
                    min_hp = other->getTeam().at(i)->getHP();
            }
        }
        for (i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive())
            {
                if (other->getTeam().at(i)->getHP() == min_hp)
                    return other->getTeam().at(i);
            }
        }
        return nullptr;
    }

    void SmartTeam::attack(Team *other) 
    {
        if(this->stillAlive() == 0)
        {
            throw invalid_argument("There are no players alive in team!!!");
        }
        if(other == nullptr)
        {
            throw invalid_argument("Team doesnt exists!!!");
        }
        if(other->stillAlive() == 0)
        {
            throw runtime_error("All team members are dead!!!");
        }
        if(other == this)
        {
            throw invalid_argument("You cannot attack yourself!!!");

        }
        if (!this->getLeader()->isAlive())
        {
            this->setLeader(victim(this));
        }

        size_t i = 0;

        for(i = 0; i < this->getTeam().size(); i++)
        {
            if(other->stillAlive() == 0)
            {
                return;
            }
            if(this->getTeam().at(i)->getType() == 2)
            {
                Ninja *c = static_cast<Ninja *>(this->getTeam().at(i));
                Character *target = ninja_victim(c,other);
                if(!c->isAlive())
                {
                    continue;
                }
                if(c->distance(target) <= 1)
                {
                    c->slash(target);
                }
                else
                {
                    c->move(target);
                }
            }
        }

        for(size_t i = 0; i < this->getTeam().size(); i++)
        {
            if(other->stillAlive() == 0)
            {
                return;
            }
            if(this->getTeam().at(i)->getType() == 1)
            {
                Cowboy *cowboy = static_cast<Cowboy*>(this->getTeam().at(i));
                Character *ch = cowboy_victim(other);
                if(!ch->isAlive())
                {
                    continue;
                }
                if(cowboy->hasboolets())
                {
                    cowboy->shoot(ch);
                }
                else
                {
                    cowboy->reload();
                }
            }
        }
    }
    void SmartTeam::print() 
    {
        size_t i = 0;

        cout << "Team - 2 - Members:" << endl << "Team Leader: " << this->getLeader()->getName() << endl << "Cowboys:" << endl;

        for(i = 0; i < this->getTeam().size(); i++)
        {
            if(this->getTeam().at(i)->getType() == 1)
            {
                cout << this->getTeam().at(i)->print() << endl;
            }
        }

        cout << "Ninjas:" << endl;

        for(i = 0; i < this->getTeam().size(); i++)
        {
            if(this->getTeam().at(i)->getType() == 2)
            {
                cout << this->getTeam().at(i)->print() << endl;
            }
        }

        cout << endl;
    }
}
