#include "directions.h"

namespace toyrobot {

const string Directions::kNorth = "NORTH";
const string Directions::kEast = "EAST";
const string Directions::kSouth = "SOUTH";
const string Directions::kWest = "WEST";

Direction Directions::Converter(string direction) {
    Direction result = kMaxValue;
    if (direction == kNorth) result = kFacingNorth;
    else if (direction == kEast) result = kFacingEast;
    else if (direction == kSouth) result = kFacingSouth;
    else if (direction == kWest) result = kFacingWest;
    return result;
}

string Directions::Converter(Direction direction) {
    string result;
    if (direction == kFacingNorth) result = kNorth;
    else if (direction == kFacingEast) result = kEast;
    else if (direction == kFacingSouth) result = kSouth;
    else if (direction == kFacingWest) result = kWest;
    return result;
}

void Directions::TurnLeft(Direction& direction) {
    if (direction == kFacingNorth) direction = kFacingWest;
    else if (direction == kFacingEast) direction = kFacingNorth;
    else if (direction == kFacingSouth) direction = kFacingEast;
    else if (direction == kFacingWest) direction = kFacingSouth;
}

void Directions::TurnRight(Direction& direction) {
    if (direction == kFacingNorth) direction = kFacingEast;
    else if (direction == kFacingEast) direction = kFacingSouth;
    else if (direction == kFacingSouth) direction = kFacingWest;
    else if (direction == kFacingWest) direction = kFacingNorth;
}

} // namespace toyrobot