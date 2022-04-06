#ifndef REQUEST_RIGHT_H_
#define REQUEST_RIGHT_H_

#include "base_request.h"
#include "request_type.h"

using namespace std;

namespace toyrobot {

class RightRequest : public BaseRequest {

public:
    explicit RightRequest(int object_id)
        : BaseRequest(RequestType::kRightRequest, object_id) {}

    BaseResponse* Execute(Table &table) override;
};

inline BaseResponse* RightRequest::Execute(Table &table) {
    table.TurnObjectRight(object_id_);
    BaseResponse *response = new BaseResponse(RequestType::kRightRequest);
    return response;
}

} // namespace toyrobot

#endif // REQUEST_RIGHT_H_