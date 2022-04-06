#include "direction.h"

namespace toyrobot {

const string Direction::kNorth = "NORTH";
const string Direction::kEast = "EAST";
const string Direction::kSouth = "SOUTH";
const string Direction::kWest = "WEST";

bool Direction::IsValidDirection(const string& d) {
    return (d == kNorth || d == kEast || d == kSouth || d == kWest);
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

ostream& operator<<(ostream& os, const Direction& d) {
    os << d.value_;
    return os;
}

} // namespace toyrobot