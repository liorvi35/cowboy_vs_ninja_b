/**
 * @brief declarations for team2 object
 * @authors Lior Vinman
 */


#ifndef TEAM_2_HPP

    #define TEAM_2_HPP

    using namespace std;

    #include "Team.hpp"
    namespace ariel
    {
        class Team2 : public Team
        {
            public:

                /**
                 * @brief standard ctor
                 */
                Team2(Character*);

                /**
                 * @brief attack method
                 * @param Team a pointer to team to attack
                 */
                void attack(Team*) override;

                /**
                 * @brief print method
                 */
                void print() override;

                /**
                * @brief find the victim character in the specified team
                * @param other a pointer to the Team object representing the other team
                * @return a pointer to the Character representing the victim character
                */
                Character* victim(Team *) override;
        };
    }

#endif