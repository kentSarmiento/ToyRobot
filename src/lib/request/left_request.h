#ifndef REQUEST_LEFT_H_
#define REQUEST_LEFT_H_

#include "base_request.h"
#include "request_type.h"

using namespace std;

namespace toyrobot {

class LeftRequest : public BaseRequest {

public:
    LeftRequest(int object_id)
        : BaseRequest(RequestType::kLeftRequest, object_id) {}

    BaseResponse* Execute(Table &table);
};

inline BaseResponse* LeftRequest::Execute(Table &table) {
    table.TurnObjectLeft(object_id_);
    BaseResponse *response = new BaseResponse(RequestType::kLeftRequest);
    return response;
}

} // namespace toyrobot

#endif // REQUEST_LEFT_H_