/**
 * @brief declarations for trained-ninja object
 * @authors Lior Vinman
 */

#ifndef TRAINED_NINJA_HPP

    #define TRAINED_NINJA_HPP

    #include <iostream>
    using namespace std;

    #include "Ninja.hpp"
    namespace ariel
    {
        class TrainedNinja : public Ninja
        {
            public:

                /**
                 * @brief standard ctor
                 * @param string name
                 * @param Point location
                 */
                TrainedNinja(string, Point);

        };
    }

#endif