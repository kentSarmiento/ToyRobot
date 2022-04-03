#include "directions.h"

namespace toyrobot {

void Directions::TurnLeft(Direction& direction) {
    switch (direction) {
        case kFacingNorth: {
            direction = kFacingWest;
            break;
        }
        case kFacingWest: {
            direction = kFacingSouth;
            break;
        }
        case kFacingSouth: {
            direction = kFacingEast;
            break;
        }
        case kFacingEast:
        default: {
            direction = kFacingNorth;
            break;
        }
    }
}

void Directions::TurnRight(Direction& direction) {
    switch (direction) {
        case kFacingNorth: {
            direction = kFacingEast;
            break;
        }
        case kFacingEast: {
            direction = kFacingSouth;
            break;
        }
        case kFacingSouth: {
            direction = kFacingWest;
            break;
        }
        case kFacingWest:
        default: {
            direction = kFacingNorth;
            break;
        }
    }
}

} // namespace toyrobot