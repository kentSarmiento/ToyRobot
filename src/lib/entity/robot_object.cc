#include <sstream>

#include "robot_object.h"
#include "direction.h"

using namespace std;

namespace toyrobot {

Coordinates RobotObject::GetMovePosition() {
    int x = position_.x;
    int y = position_.y;

    if (facing_.IsNorth()) y++;
    else if (facing_.IsEast()) x++;
    else if (facing_.IsSouth()) y--;
    else if (facing_.IsWest()) x--;

    return Coordinates(x, y);
}

void RobotObject::Move() {
    position_ = GetMovePosition();
}

string RobotObject::Report() {
    stringstream outstream;
    outstream << position_ << "," << facing_;
    return outstream.str();
}

} // namespace toyrobot