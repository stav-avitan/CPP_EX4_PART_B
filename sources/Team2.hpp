#pragma once
#include "Team.hpp"
using namespace std;

namespace ariel
{
    class Team2 : public Team
    {
    public:
        void add(Character *) override;
        Team2(Character *);
        
    };

}