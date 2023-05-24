#pragma once
#include "Ninja.hpp"
namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name, const Point &location) : Ninja(std::move(name), location, OLD_NINJA_HP, OLD_NINJA_SPEED) {}
    };
}
