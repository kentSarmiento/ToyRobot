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

    static const string kNorth;
    static const string kEast;
    static const string kSouth;
    static const string kWest;

    static bool IsValidDirection(string d);

    void TurnLeft();
    void TurnRight();

    string value() { return value_; }

private:

    string value_;
};

} // namespace toyrobot

#endif // VALUE_DIRECTION_H_