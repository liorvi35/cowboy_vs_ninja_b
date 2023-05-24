/**
 * @brief implementations for trained-ninja object
 * @authors Lior Vinman
 */

#include <iostream>
using namespace std;

#include "TrainedNinja.hpp"
namespace ariel
{
    TrainedNinja::TrainedNinja(string name, Point loc) : Ninja(name, loc, 12, 120) {}
}