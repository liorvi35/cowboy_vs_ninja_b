/**
 * @brief declarations for ninja object
 * @authors Lior Vinman
 */


#ifndef NINJA_HPP

    #define NINJA_HPP

    #include <iostream>
    #include <string>
    using namespace std;

    #include "Character.hpp"
    namespace ariel
    {
        class Ninja : public Character
        {
            private:

                /**
                 * @brief moving speed of ninja
                 */
                int _speed;

            public:

                /**
                 * @brief default ctor
                 */
                Ninja();

                /**
                 * @brief standard ctor
                 * @param string name
                 * @param Point location
                 * @param int healthPoints
                 * @param int speed
                 */
                Ninja(string, Point, int , int);

                /**
                 * @brief move function
                 * @param Character pointer to character to move to
                 */
                void move(Character *);

                /**
                 * @brief a slash method
                 * @param Character character to slash
                 */
                void slash(Character *);

                /**
                 * @brief getter for speed
                 * @return speed
                 */
                int getSpeed();

                /**
                 * @brief setter for speed
                 * @param int new speed
                 */
                void setSpeed(int);

                /**
                 * @brief print method
                 * @return string representing ninja
                 */
                string print() override;
        };
    }

#endif