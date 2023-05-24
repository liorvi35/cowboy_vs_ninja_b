/**
 * @brief declarations for cowboy object
 * @authors Lior Vinman
 */

#ifndef COWBOY_HPP

    #define COWBOY_HPP

    #include <iostream>
    using namespace std;

    #include "Character.hpp"
    namespace ariel
    {
        class Cowboy : public Character
        {
            private:

                /**
                 * @brief amount of bullets
                 */
                int _bullets;

            public:

                /**
                 * @brief standard ctor
                 */
                Cowboy(string, Point);

                /**
                 * @brief method to shoot another player
                 */
                void shoot(Character*);

                /**
                 * @brief boolet checker
                 * @return true if num of boolets > 0, false else
                 */
                bool hasboolets();

                /**
                 * @brief method to reload weapon
                 */
                void reload();

                /**
                 * @brief method to print cowboy object
                 * @return string that represents cowboy
                 */
                string print() override;
        };
    }

#endif