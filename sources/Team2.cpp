/**
 * @brief implementations for team2 object
 * @authors Lior Vinman
 */

#include <iostream>
using namespace std;

#include "Team2.hpp"
namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader) {}

    void Team2::attack(Team *other)
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

        Character *other_victim = this->victim(other);

        for(size_t i = 0; i < this->getTeam().size(); i++)
        {
            if(other->stillAlive() == 0)
            {
                return;
            }

            if(!other_victim->isAlive())
            {
                other_victim = victim(other);
            }

            if(this->getTeam().at(i)->getType() == 1)
            {
                Cowboy *c = static_cast<Cowboy *>(this->getTeam().at(i));
                if(!c->isAlive())
                {
                    continue;
                }
                if(!c->hasboolets())
                {
                    c->reload();
                }
                else
                {
                    c->shoot(other_victim);
                }
            }
        }

        for(size_t i = 0; i < this->getTeam().size(); i++)
        {
            if(other->stillAlive() == 0)
            {
                return;
            }

            if(!other_victim->isAlive())
            {
                other_victim = victim(other);
            }

            if(this->getTeam().at(i)->getType() == 2)
            {
                Ninja *c = static_cast<Ninja *>(this->getTeam().at(i));

                if(!c->isAlive())
                {
                    continue;
                }
                if(c->distance(other_victim) <= 1)
                {
                    c->slash(other_victim);
                }
                else
                {
                    c->move(other_victim);
                }
            }
        }
    }

    Character* Team2::victim(Team *other)
    {
        double max = __DBL_MAX__;
        for (size_t i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive())
            {
                if (other->getTeam().at(i)->distance(this->getLeader()) < max)
                {
                    max = other->getTeam().at(i)->distance(this->getLeader());
                }
            }
        }
        for (size_t i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive())
            {
                if (other->getTeam().at(i)->distance(this->getLeader()) == max)
                {
                    return other->getTeam().at(i);
                }
            }
        }
        return nullptr;
    }

    void Team2::print()
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
