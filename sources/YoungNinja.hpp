/**
 * @brief declarations for young-ninja object
 * @authors Lior Vinman
 */

#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

    #include <iostream>
    #include <string>
    using namespace std;

    #include "Ninja.hpp"
    namespace ariel
    {
        class YoungNinja : public Ninja
        {
            public:

                /**
                 * @brief standard ctor
                 * @param string name
                 * @param Point location
                 */
                YoungNinja(string, Point);

        };
    }

#endif
