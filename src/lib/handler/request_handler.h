#ifndef REQUEST_HANDLER_H_
#define REQUEST_HANDLER_H_

#include "base_request.h"
#include "base_response.h"

namespace toyrobot {

class RequestHandler {

public:
    static BaseResponse* HandleCommand(BaseRequest* request);
};

} // namespace toyrobot

#endif // REQUEST_HANDLER_H_