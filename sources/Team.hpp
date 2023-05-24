#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>

namespace ariel
{
    class Team
    {
    private:
        vector<Character *> team;
        Character *theLeader;

    public:
        
       virtual ~Team(){};
        Team(Team &&) noexcept;
        virtual void add(Character *);
        void print() const;
        Team(Character *theLeader);
        Team &operator=(Team &&) noexcept;
        Team(const Team &);
        int stillAlive();
        void attack(Team *);
        Character *closestMember(vector<Character *> &, const Point &);
        Team &operator=(const Team &);
        Character *gettheLeader()
        {
            return theLeader;
        }
        vector<Character *> &getTeam()
        {
            return team;
        }
    };

}