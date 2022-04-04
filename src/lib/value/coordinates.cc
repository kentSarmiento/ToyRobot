#include <iostream>

#include "coordinates.h"

using namespace std;

namespace toyrobot {

ostream& operator<<(ostream& os, const Coordinates& pos) {
    os << pos.x << "," << pos.y;
    return os;
}

} // namespace toyrobot