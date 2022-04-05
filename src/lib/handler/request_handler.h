#ifndef REQUEST_HANDLER_H_
#define REQUEST_HANDLER_H_

#include <list>

#include "base_request.h"
#include "base_response.h"

using namespace std;

namespace toyrobot {

class RequestHandler {

public:
    RequestHandler() {}

    ~RequestHandler();

    BaseResponse* HandleCommand(BaseRequest* request);

private:
    list<pair<BaseRequest*, BaseResponse*>> transactions_;
    Table table;
};

} // namespace toyrobot

#endif // REQUEST_HANDLER_H_