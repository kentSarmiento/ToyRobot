#ifndef VALUE_COORDINATES_H_
#define VALUE_COORDINATES_H_

namespace toyrobot {

struct Coordinates {
    int x;
    int y;

    Coordinates() : x(0), y(0) {}
    Coordinates(int x, int y) : x(x), y(y) {}
};

} // namespace toyrobot

#endif // VALUE_COORDINATES_H_