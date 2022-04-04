#ifndef RESPONSE_PLACE_H_
#define RESPONSE_PLACE_H_

#include <string>

#include "base_response.h"
#include "request_type.h"

using namespace std;

namespace toyrobot {

class PlaceResponse : public BaseResponse {

public:
    PlaceResponse(int object_id)
        : BaseResponse(RequestType::kPlaceRequest) {
        object_id_ = object_id;
    }

    void TakeValue(int &value) override;

protected:
    int object_id_;
};

inline void PlaceResponse::TakeValue(int &value) {
    value = object_id_;
}

} // namespace toyrobot

#endif // RESPONSE_PLACE_H_