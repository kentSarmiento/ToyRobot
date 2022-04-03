#ifndef VALUE_DIRECTIONS_H_
#define VALUE_DIRECTIONS_H_

#include <string>
using namespace std;

namespace toyrobot {

enum Direction {
    kFacingNorth,
    kFacingEast,
    kFacingSouth,
    kFacingWest,

    kMaxValue,
};

class Directions {
public:
    static Direction Converter(string direction);
    static string Converter(Direction direction);
    static void TurnLeft(Direction& direction);
    static void TurnRight(Direction& direction);

private:
    static const string kNorth;
    static const string kEast;
    static const string kSouth;
    static const string kWest;
};

} // namespace toyrobot

#endif // VALUE_DIRECTION_H_