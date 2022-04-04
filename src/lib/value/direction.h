#ifndef VALUE_DIRECTION_H_
#define VALUE_DIRECTION_H_

#include <string>
using namespace std;

namespace toyrobot {

class Direction {

public:
    Direction() {
        value_ = kNorth;
    }

    Direction(string d) {
        value_ = d;
    }

    static bool IsValidDirection(string d);

    void TurnLeft();
    void TurnRight();

    bool IsNorth() { return value_ == kNorth; }
    bool IsEast() { return value_ == kEast; }
    bool IsSouth() { return value_ == kSouth; }
    bool IsWest() { return value_ == kWest; }

    friend ostream& operator<<(ostream& os, const Direction& d);

private:
    static const string kNorth;
    static const string kEast;
    static const string kSouth;
    static const string kWest;

    string value_;
};

} // namespace toyrobot

#endif // VALUE_DIRECTION_H_