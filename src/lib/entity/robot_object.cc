#include <sstream>

#include "robot_object.h"
#include "directions.h"

using namespace std;

namespace toyrobot {

Coordinates RobotObject::GetMovePosition() {
    int x = position_.x;
    int y = position_.y;

    switch (facing_) {
        case kFacingNorth: {
            y++;
            break;
        }
        case kFacingEast: {
            x++;
            break;
        }
        case kFacingSouth: {
            y--;
            break;
        }
        case kFacingWest:
        default: {
            x--;
            break;
        }
    }

    return Coordinates(x, y);
}

void RobotObject::Move() {
    position_ = GetMovePosition();
}

string RobotObject::Report() {
    stringstream outstream;
    outstream << position_.x << ",";
    outstream << position_.y << ",";
    outstream << Directions::Converter(facing_);
    return outstream.str();
}

} // namespace toyrobot