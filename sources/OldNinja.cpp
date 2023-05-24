/**
 * @brief implementations for old-ninja object
 * @authors Lior Vinman
 */

#include <iostream>
using namespace std;

#include "OldNinja.hpp"
namespace ariel
{
    OldNinja::OldNinja(string name, Point loc) : Ninja(name, loc, 8, 150) {}
}