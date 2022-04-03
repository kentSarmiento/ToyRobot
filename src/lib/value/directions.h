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
    static Direction converter(string direction);
    static string converter(Direction direction);
    static Direction left(Direction direction);
    static Direction right(Direction direction);

private:
    static const string kDirections[];
};

} // namespace toyrobot

#endif // VALUE_DIRECTION_H_