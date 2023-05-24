#include "Cowboy.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>
using namespace std;
namespace ariel
{

    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), amountOfBullets(6) {}

   bool Cowboy::hasboolets()
{
    return amountOfBullets > 0;
}


    void Cowboy::reload()
{
    if (!isAlive())
    {
        throw std::runtime_error("Cowboy is not alive");
    }
    
    amountOfBullets = 6;
}
  void Cowboy::shoot(Character *target)
    {
if (!isAlive())
{
    throw std::runtime_error("The cowboy is deceased.");
}
else if (this == target)
{
    throw std::runtime_error("Self-attack is not permitted.");
}
else if (!target->isAlive())
{
    throw std::runtime_error("The specified target is deceased.");
}
else if (hasboolets())
{
    target->hit(10);
    setAmoutOfBullets();
}
    }

    void Cowboy::attack(Character* enemy) {
    if (!isAlive() || !enemy->isAlive()) {
        return;
    }

    if (hasboolets()) {
        shoot(enemy);
    } else {
        reload();
    }
}


    string Cowboy::print() {
    string nameStr = " (C)The name of the character is: " + getName();
    string locationStr = "The location is: " + getLocation().print();
    string vitalityStr = "He has " + to_string(getvitality()) + " hit points";

    if (!isAlive()) {
        nameStr = "The Character name is: (" + getName() + ")";
        vitalityStr = "";
    }

    return nameStr + " " + locationStr + " " + vitalityStr;
}
}