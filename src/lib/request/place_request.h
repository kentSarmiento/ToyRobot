#ifndef REQUEST_PLACE_H_
#define REQUEST_PLACE_H_

#include <sstream>

#include "base_request.h"
#include "place_response.h"
#include "coordinates.h"
#include "direction.h"
#include "request_type.h"

using namespace std;

namespace toyrobot {

class PlaceRequest : public BaseRequest {

public:
    PlaceRequest(const string& data)
        : BaseRequest(RequestType::kPlaceRequest) {
        is_valid_ = false;
        ParseData(data);
    }

    PlaceRequest(int object_id, const string& data)
        : BaseRequest(RequestType::kPlaceRequest, object_id) {
        is_valid_ = false;
        ParseData(data);
    }

    BaseResponse* Execute(Table &table) override;

    Coordinates position() { return position_; }
    Direction facing() { return facing_; }

private:
    Coordinates position_;
    Direction facing_;

    void ParseData(string data);
};

} // namespace toyrobot

#endif // REQUEST_PLACE_H_