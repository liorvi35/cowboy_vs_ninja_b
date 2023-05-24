/**
 * @brief declarations for team object
 * @authors Lior Vinman
 */


#ifndef TEAM_HPP

    #define TEAM_HPP

    #include <vector>
    using namespace std;

    #include "YoungNinja.hpp"
    #include "TrainedNinja.hpp"
    #include "OldNinja.hpp"
    #include "Cowboy.hpp"
    namespace ariel
    {
        class Team
        {
            private:

                /**
                 * @brief list of team members
                 */
                vector<Character*> _teamMates;

                /**
                 * @brief team leader
                 */
                Character* _leader;

            public:

                /**
                 * @brief standard ctor
                 * @param Character team leader
                 */
                Team(Character*);

                /**
                 * @brief destructor, deletes all objects
                 */
                virtual ~Team()
                {
                    size_t i = 0;
                    for (; i < _teamMates.size(); i++)
                        {
                            delete _teamMates.at(i);
                        }
                }

                /**
                 * @brief adds new team member
                 */
                void add(Character*);

                /**
                 * @brief check how many team members are alive
                 * @return count
                 */
                int stillAlive();

                /**
                 * @brief attack (war) between two teams
                 */
                virtual void attack(Team*);

                /**
                 * @brief prints team members & leader
                 */
                virtual void print();

                /**
                 * @brief find the victim character in the specified team
                 * @param other a pointer to the Team object representing the other team
                 * @return a pointer to the Character representing the victim character
                 */
                virtual Character* victim(Team *);

                /**
                 * @brief get the team members
                 * @return A reference to the vector of Character pointers representing the team members
                 */
                vector<Character*>& getTeam();

                /**
                 * @brief get the leader of the team
                 * @return A pointer to the Character representing the team leader
                 */
                Character* getLeader();

                /**
                 * @brief set the leader of the team
                 * @param leader A pointer to the Character to be set as the team leader
                 */
                void setLeader(Character* leader);

        };
    }

#endif