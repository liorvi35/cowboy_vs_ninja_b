/**
 * @brief declarations for character object
 * @authors Lior Vinman
 */

#ifndef CHARACTER_HPP

    #define CHARACTER_HPP

    #include <iostream>
    #include <string>
    using namespace std;

    #include "Point.hpp"

    namespace ariel
    {
        class Character
        {
            private:

                /**
                 * @brief the location of character on board
                 */
                Point _location;

                /**
                 * @brief amount of health
                 */
                int _healthPoints;

                /**
                 * @brief players name
                 */
                string _name;

                /**
                 * @brief is player in team
                 */
                bool _team;

                /**
                 * @brief type of character: 1 - cowboy, 2 - ninja
                 */
                int _type;

            public:

                /**
                 * @brief default ctor
                 */
                Character();

                /**
                 * @brief standard ctor
                 * @param string name
                 * @param Point location
                 * @param int health points
                 */
                Character(string, const Point, int);

                /**
                * @brief default destructor
                */
                virtual ~Character() = default;

                /**
                 * @brief checks if player is alive (health > 0)
                 * @return true if alive, false else
                 */
                bool isAlive();

                /**
                 * @brief checks the distance between two characters
                 * @param Character pointer to another player
                 * @return distance in CM
                 */
                double distance(Character*);

                /**
                 * @brief function to deal damage to player
                 * @param int amount of damage
                 */
                void hit(int);

                /**
                 * @brief print method to character (empty)
                 * @return string that represents the character
                 */
                virtual string print();

                /**
                 * @brief getter for name
                 * @return name
                 */
                string getName();

                /**
                 * @brief getter for location
                 * @return location
                 */
                Point getLocation();

                /**
                 * @brief getter for health points
                 * @return healthPoints
                 */
                int getHP();

                /**
                 * @brief getter for team
                 * @return team
                 */
                bool getTeam();

                /**
                 * @brief getter for type
                 * @return type
                 */
                int getType();

                /**
                 * @brief setter for location
                 * @param Point pointer to new location
                 */
                void setLocation(Point&);

                /**
                 * @brief setter for team
                 * @param bool true if in team, false else
                 */
                void setTeam(bool);

                /**
                 * @brief setter for type
                 * @param int 1 - cowboy, 2 - ninja
                 */
                void setType(int);
        };
    }

#endif