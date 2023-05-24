/**
 * @brief declarations for smart-team object
 * @authors Lior Vinman
 */


#ifndef SMART_TEAM_HPP

    #define SMART_TEAM_HPP

    using namespace std;

    #include "Team.hpp"
    namespace ariel
    {
        class SmartTeam : public Team
        {
            public:

                /**
                 * @brief standard ctor
                 * @param Character team leader
                 */
                SmartTeam(Character*);

                /**
                 * @brief attack method
                 * @param Team a team to attack
                 */
                void attack(Team*) override;

                /**
                 * @brief printer method
                 */
                void print() override;

                /**
                * @brief find the victim for a given Ninja
                * @param Ninja The Ninja object
                * @param Team The other Team object
                * @return The Character object that is the victim for the Ninja
                */
                Character* ninja_victim(Ninja*, Team*);

                /**
                * @brief find the victim for the Cowboys in the team
                * @param Team The other Team object
                * @return The Character object that is the victim for the Cowboys
                */
                Character* cowboy_victim(Team*);
        };
    }

#endif