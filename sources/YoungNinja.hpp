#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string name, const Point &location) : Ninja(std::move(name), location, YOUNG_NINJA_HP, YOUNG_NINJA_SPEED) {}
    };
}