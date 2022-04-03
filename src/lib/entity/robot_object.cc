#include "robot_object.h"

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

string RobotObject::Report() { return ""; }

} // namespace toyrobot