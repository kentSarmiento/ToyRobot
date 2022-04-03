#include <sstream>

#include "robot_object.h"
#include "directions.h"

using namespace std;

namespace toyrobot {

void RobotObject::Move() {
    switch (facing_) {
        case kFacingNorth: {
            position_.y++;
            break;
        }
        case kFacingEast: {
            position_.x++;
            break;
        }
        case kFacingSouth: {
            position_.y--;
            break;
        }
        case kFacingWest:
        default: {
            position_.x--;
            break;
        }
    }
}

string RobotObject::Report() {
    stringstream outstream;
    outstream << position_.x << ",";
    outstream << position_.y << ",";
    outstream << Directions::Converter(facing_);
    return outstream.str();
}

} // namespace toyrobot