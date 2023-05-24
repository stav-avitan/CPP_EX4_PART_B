#include "Point.hpp"
#include <string>
#include <sstream>

using namespace std;
using namespace ariel;

Point::Point() : x(0), y(0)
{
}

Point::Point(double x, double y) : x(x), y(y)
{
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::distance(Point other) const {
    double resX = getX() - other.getX();
    double resY = getY() - other.getY();
    double squaredDistance = resX * resX + resY * resY;
    return std::sqrt(squaredDistance);
}


std::string Point::print() {
    std::ostringstream oss;
    oss << "(" << x << " , " << y << ")";
    return oss.str();
}


Point Point::moveTowards(const Point &p1, const Point &p2, const double distance)
{
   if (distance < 0) {
        throw std::invalid_argument("Negative distance is not allowed!");
    }

    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();
    double totalDistance = p1.distance(p2);

    if (distance > totalDistance) {
        return p2;
    }

    double ratio = distance / totalDistance;
    double newX = p1.getX() + ratio * dx;
    double newY = p1.getY() + ratio * dy;

    return Point(newX, newY);
}
