/**
 * @brief declarations for old-ninja object
 * @authors Lior Vinman
 */

#ifndef OLD_NINJA_HPP

    #define OLD_NINJA_HPP

    #include <iostream>
    #include <string>
    using namespace std;

    #include "Ninja.hpp"
    namespace ariel
    {
        class OldNinja : public Ninja
        {
            public:

                /**
                 * @brief standard ctor
                 * @param string name
                 * @param Point location
                 */
                OldNinja(string, Point);
        };
    }

#endif