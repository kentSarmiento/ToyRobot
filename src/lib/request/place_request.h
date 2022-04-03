#ifndef REQUEST_PLACE_H_
#define REQUEST_PLACE_H_

#include <sstream>

#include "base_request.h"
#include "coordinates.h"
#include "directions.h"
#include "request_type.h"

using namespace std;

namespace toyrobot {

class PlaceRequest : public BaseRequest {

public:
    PlaceRequest(int id, string args)
        : BaseRequest(RequestType::kPlaceRequest, id) {
        is_valid_ = false;

        stringstream input_stream(args);
        char c;
        int x, y;

        if ((input_stream >> x) && (input_stream >> c) &&
            (input_stream >> y) && (input_stream >> c) &&
            (input_stream >> args)) {
            position_ = Coordinates(x, y);
            direction_ = Directions::Converter(args);
            if (direction_ != kMaxValue) is_valid_ = true;
        }
    }

    Coordinates position() { return position_; }
    Direction direction() { return direction_; }

private:
    Coordinates position_;
    Direction direction_;
};

} // namespace toyrobot

#endif // REQUEST_PLACE_H_