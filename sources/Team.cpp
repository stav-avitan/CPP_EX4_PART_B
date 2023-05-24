#include "Team.hpp"
#include "Character.hpp"
#include <cfloat>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
namespace ariel
{
   Team::Team(Character* theLeader) : theLeader(theLeader) {
    if (theLeader->getInTeam()) {
        throw std::runtime_error("The leader is already part of a team.");
    }

    theLeader->setTeam(true);
    team.push_back(theLeader);
}

  Team::Team(const Team &other) : theLeader(other.theLeader) {}

  Team::Team(Team &&other) noexcept
  {
    theLeader = other.theLeader;
    team = other.team;
  }

  Team &Team::operator=(const Team &other)
  {
    theLeader = other.theLeader;
    team = other.team;
    return *this;
  }

  Team &Team::operator=(Team &&other) noexcept
  {
    theLeader = other.theLeader;
    team = other.team;
    return *this;
  }
  

  void Team::attack(Team *other)
  {
 // Check if 'other' is nullptr
if (!other) {
throw invalid_argument("The enemy target is null.");
}

// Check if either team is completely dead
if (stillAlive() == 0 || other->stillAlive() == 0) {
throw runtime_error("At least one of the teams is no longer alive.");
}

// Ensure the theLeader is alive, or find the closest alive member within this team as the new theLeader
theLeader = (theLeader->isAlive()) ? theLeader : closestMember(this->team, theLeader->getLocation());

// Find the closest alive member in the 'other' team as the initial target
Character* target = (other->stillAlive() > 0) ? closestMember(other->team, theLeader->getLocation()) : nullptr;

// Attack the target for each alive member in this team
for (auto member : team) {
if (member && member->isAlive()) {
if (target && target->isAlive()) {
member->attack(target);
} else {
target = closestMember(other->team, theLeader->getLocation());
if (target && target->isAlive()) {
member->attack(target);
}
}
}
}
  }

  void Team::add(Character* newChar) {
if (newChar && newChar->isAlive() && !newChar->getInTeam() && team.size() < 10) {
if (typeid(*newChar) == typeid(Cowboy)) {
team.insert(team.begin(), newChar);
} else {
team.push_back(newChar);
}
newChar->setTeam(true);
} else {
throw runtime_error("Unable to add this Character.");
}
}

  int Team::stillAlive()
{
  int counter = std::count_if(team.begin(), team.end(), [](Character* member) {
    return member->isAlive();
  });
  return counter;
}

void Team::print() const {
for (const auto& member : team) {
if (member != nullptr) {
cout << member->print() << endl;
}
}
}

  Character *Team::closestMember(vector<Character *> &other, const Point &)
  {
    Character* result = nullptr;
auto it = other.begin();
double minDistance = DBL_MAX;

while (it != other.end()) {
Character* member = *it;
if (member->isAlive() && theLeader->distance(member) < minDistance) {
minDistance = theLeader->distance(member);
result = member;
}
++it;
}

return result;
  }

  
}