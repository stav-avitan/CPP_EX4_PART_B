#pragma once
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point location;
        int vitality;
        string name;
        bool inTeam;

    public:
        double distance(Character *);
        Character(const string &name, const Point &location, int vitality);
        Character(const Character &other);
        Character &operator=(const Character &other);
        Character &operator=(Character &&other) noexcept;
        virtual void attack(Character *enemy) = 0;
        bool isAlive() const noexcept;
        void hit(int);
        virtual string print() = 0;
        Character(Character &&other) noexcept;
        bool getInTeam()
        {
            return this->inTeam;
        }
        void setTeam(bool flag)
        {
            this->inTeam = flag;
        }
        Point getLocation() 
        {
            return this->location;
        }
        void setLocation(Point newLocation)
        {
            this->location = newLocation;
        }
        int getvitality()
        {
            return this->vitality;
        }
        void setvitality(int vitality)
        {
            this->vitality = vitality;
        }
        string getName()
        {
            return this->name;
        }
    };
}