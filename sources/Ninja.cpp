#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <string>
#include <iostream>
using namespace std;
namespace ariel
{

    Ninja ::Ninja(string name, const Point &location, int vitality, int speed) : Character(name, location, vitality), speed(speed) {}

    void Ninja::move(Character* target) {
    if (!isAlive()) {
        return;
    }

    Point source = getLocation();
    Point destination = target->getLocation();
    Point tmp = Point::moveTowards(source, destination, getSpeed());
    setLocation(tmp);
}

int Ninja::getSpeed()
        {
            return speed;
        }
    void Ninja::slash(Character* target) {
        if (target == nullptr || !target->isAlive()) {
        throw std::runtime_error("Target is invalid or no longer alive");
    }
     if (this == target) {
        throw std::runtime_error("Invalid action: attacking oneself");
    }
    if (!isAlive()) {
        throw std::runtime_error("Ninja is lifeless");
    }

    double distance = getLocation().distance(target->getLocation());
    if (distance < 1) {
        target->hit(40);
    }
}


   void Ninja::attack(Character* other) {
    if ( !other->isAlive()|| !isAlive()) {
        return;
    }

    double distance = getLocation().distance(other->getLocation());
    if (distance <= 1) {
        slash(other);
    } else {
        move(other);
    }
}


    string Ninja::print() {
    string nameStr = "(N) The Character name is: " + getName();
    string locationStr = "His location is: " + getLocation().print();
    string healthStr = isAlive() ? "He has " + to_string(getvitality()) + " hit points" : "";

    return nameStr + " " + locationStr + " " + healthStr;
}
}