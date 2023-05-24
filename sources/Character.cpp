#include <iostream>
#include <string>
#include <stdexcept>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
using namespace std;
namespace ariel
{

    Character::Character(Character &&other) noexcept : name(other.name), location(other.location), vitality(other.vitality), inTeam(other.inTeam) {}


    Character::Character(const Character &other) : name(other.name), location(other.location), vitality(other.vitality), inTeam(other.inTeam) {
        
    }

    Character::Character(const string &name, const Point &location, int vitality) : name(name), location(location), vitality(vitality), inTeam(false) {

    }

double Character::distance(Character* other)
{
    if (!other)
    {
        throw std::invalid_argument("You cannot assign a null value as a character!!!");
    }

    Point otherPoint = other->getLocation();
    return getLocation().distance(otherPoint);
}


    Character& Character::operator=(Character&& other) noexcept
{
    if (this == &other)
        return *this;

    name = std::move(other.name);
    location = std::move(other.location);
    vitality = other.vitality;
    inTeam = other.inTeam;

    return *this;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		vitality = other.vitality;
		name = other.name;
	}

	return *this;
}


bool Character::isAlive() const noexcept
{
    return (vitality > 0);
}



    

    void Character::hit(int damage)
{
    if (damage < 0)
    {
        throw std::invalid_argument("The number of hits cannot be negative!!!");
    }

    vitality = std::max(vitality - damage, 0);
}
}
