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
};

class Directions {
public:
    static Direction Converter(string direction);
    static string Converter(Direction direction);
    static void TurnLeft(Direction& direction);
    static void TurnRight(Direction& direction);

private:
    static const string kDirections[];
};

} // namespace toyrobot

#endif // VALUE_DIRECTION_H_