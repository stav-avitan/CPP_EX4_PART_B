#pragma once
#include "Character.hpp"

using namespace std;
constexpr int OLD_NINJA_HP= 150;
constexpr int OLD_NINJA_SPEED =8;
constexpr int TRAINED_NINJA_SPEED =12;
constexpr int TRAINED_NINJA_HP =120;
constexpr int YOUNG_NINJA_HP = 100;
constexpr int YOUNG_NINJA_SPEED= 14;

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(string name, const Point& location, int vitality, int speed);
        int getSpeed();
        void attack(Character *) override;
        void slash(Character *);
        void move(Character *);
        string print() override;
       
        
    };


}