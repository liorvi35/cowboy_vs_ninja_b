/**
 * @brief implementations for team object
 * @authors Lior Vinman
 */


#include <iostream>
using namespace std;

#include "Team.hpp"
namespace ariel
{
    Team::Team(Character *ch)
    {
        if(ch->getTeam())
        {
            throw runtime_error("Character already inside team!!!");
        }

        _leader = ch;
        _teamMates.push_back(ch);
        ch->setTeam(true);
    }

    void Team::add(Character *ch)
    {
        if (ch->getTeam())
        {
            throw runtime_error("Character already inside team!!!");
        }
        else if (_teamMates.size() == 10)
        {
            throw runtime_error("Team is in maximum capacity!!!");
        }

        _teamMates.push_back(ch);

        ch->setTeam(true);
    }

    Character* Team::victim(Team *other)
    {
        double max = __DBL_MAX__;

        size_t i = 0;

        for (i = 0; i < other->_teamMates.size(); i++)
        {
            if (other->_teamMates.at(i)->isAlive() && other->_teamMates.at(i)->getType() == 1)
            {
                if (other->_teamMates.at(i)->distance(_leader) < max)
                {
                    max = other->_teamMates.at(i)->distance(_leader);
                }
            }
        }

        for (i = 0; i < other->_teamMates.size(); i++)
        {
            if (other->_teamMates.at(i)->isAlive() && other->_teamMates.at(i)->getType() == 2)
            {
                if (other->_teamMates.at(i)->distance(_leader) < max)
                {
                    max = other->_teamMates.at(i)->distance(_leader);
                }
            }
        }

        for (i = 0; i < other->_teamMates.size(); i++)
        {
            if (other->_teamMates.at(i)->isAlive() && other->_teamMates.at(i)->getType() == 1)
            {
                if (other->_teamMates.at(i)->distance(_leader) == max)
                {
                    return other->_teamMates.at(i);
                }
            }
        }

        for (i = 0; i < other->_teamMates.size(); i++)
        {
            if (other->_teamMates.at(i)->isAlive() && other->_teamMates.at(i)->getType() == 2)
            {
                if (other->_teamMates.at(i)->distance(_leader) == max)
                {
                    return other->_teamMates.at(i);
                }
            }
        }

        return nullptr;
    }

    void Team::attack(Team *other)
    {
        if(stillAlive() == 0)
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

        if (!_leader->isAlive())
        {
            _leader = victim(this);
        }

        Character *other_victim = victim(other);

        for(size_t i = 0; i < _teamMates.size(); i++)
        {
            if(other->stillAlive() == 0)
            {
                return;
            }

            if(!other_victim->isAlive())
            {
                other_victim = victim(other);
            }

            if(_teamMates.at(i)->getType() == 1)
            {
                Cowboy *c = static_cast<Cowboy *>(_teamMates.at(i));
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

        for(size_t i = 0; i < _teamMates.size(); i++)
        {
            if(other->stillAlive() == 0)
            {
                return;
            }

            if(!other_victim->isAlive())
            {
                other_victim = victim(other);
            }

            if(_teamMates.at(i)->getType() == 2)
            {
                Ninja *c = static_cast<Ninja *>(_teamMates.at(i));

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

    int Team::stillAlive()
    {
        int alive = 0;

        for (size_t i = 0; i < _teamMates.size(); i++)
        {
            if (_teamMates.at(i)->isAlive())
            {
                alive++;
            }
        }

        return alive;

    }

    vector<Character *>& Team::getTeam()
    {
        return _teamMates;
    }

    Character* Team::getLeader()
    {
        return _leader;
    }

    void Team::setLeader(Character* leader)
    {
        _leader = leader;
    }

    void Team::print()
    {
        size_t i = 0;

        cout << "Team - 1 - Members:" << endl << "Team Leader: " << _leader->getName() << endl << "Cowboys:" << endl;

        for(i = 0; i < _teamMates.size(); i++)
        {
            if(_teamMates.at(i)->getType() == 1)
            {
                cout << _teamMates.at(i)->print() << std::endl;
            }
        }

        cout << "Ninjas:" << endl;

        for(i = 0; i < _teamMates.size(); i++)
        {
            if(_teamMates.at(i)->getType() == 2)
            {
                cout << _teamMates.at(i)->print() << std::endl;
            }
        }

        cout << endl;
    }
}
