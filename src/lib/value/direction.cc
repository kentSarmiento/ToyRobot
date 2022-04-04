#include "direction.h"

namespace toyrobot {

const string Direction::kNorth = "NORTH";
const string Direction::kEast = "EAST";
const string Direction::kSouth = "SOUTH";
const string Direction::kWest = "WEST";

bool Direction::IsValidDirection(string d) {
    if (d != kNorth && d != kEast && d != kSouth && d != kWest)
        return false;
    return true;
}

void Direction::TurnLeft() {
    if (value_ == kNorth) value_ = kWest;
    else if (value_ == kEast) value_ = kNorth;
    else if (value_ == kSouth) value_ = kEast;
    else if (value_ == kWest) value_ = kSouth;
}

void Direction::TurnRight() {
    if (value_ == kNorth) value_ = kEast;
    else if (value_ == kEast) value_ = kSouth;
    else if (value_ == kSouth) value_ = kWest;
    else if (value_ == kWest) value_ = kNorth;
}

} // namespace toyrobot