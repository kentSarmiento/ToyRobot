#ifndef REQUEST_MOVE_H_
#define REQUEST_MOVE_H_

#include "base_request.h"
#include "request_type.h"

using namespace std;

namespace toyrobot {

class MoveRequest : public BaseRequest {

public:
    explicit MoveRequest(int object_id)
        : BaseRequest(RequestType::kMoveRequest, object_id) {}

    BaseResponse* Execute(Table &table) override;
};

inline BaseResponse* MoveRequest::Execute(Table &table) {
    table.MoveObject(object_id_);
    BaseResponse *response = new BaseResponse(RequestType::kMoveRequest);
    return response;
}

} // namespace toyrobot

#endif // REQUEST_MOVE_H_