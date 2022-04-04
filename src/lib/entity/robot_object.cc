#include <sstream>

#include "robot_object.h"
#include "direction.h"

using namespace std;

namespace toyrobot {

Coordinates RobotObject::GetMovePosition() {
    int x = position_.x;
    int y = position_.y;

    if (facing_.value() == Direction::kNorth) y++;
    else if (facing_.value() == Direction::kEast) x++;
    else if (facing_.value() == Direction::kSouth) y--;
    else if (facing_.value() == Direction::kWest) x--;

    return Coordinates(x, y);
}

void RobotObject::Move() {
    position_ = GetMovePosition();
}

string RobotObject::Report() {
    stringstream outstream;
    outstream << position_.x << ",";
    outstream << position_.y << ",";
    outstream << facing_.value();
    return outstream.str();
}

} // namespace toyrobot