#include "Team2.hpp"
using namespace std;
#include <vector>

namespace ariel
{
    Team2::Team2(Character *theLeader) : Team(theLeader)
    {
    }

    void Team2::add(Character *newChar)
    {
        if (newChar && newChar->isAlive() && !newChar->getInTeam() && getTeam().size() < 10) {
    getTeam().push_back(newChar);
    newChar->setTeam(true);
    } else {
    throw runtime_error("Unable to add this Character.");
    }
    }
}