/**
 * @brief implementations for young-ninja object
 * @authors Lior Vinman
 */

#include <iostream>
using namespace std;

#include "YoungNinja.hpp"
namespace ariel
{
    YoungNinja::YoungNinja(string name, Point loc) : Ninja(name, loc, 14, 100) {}
}