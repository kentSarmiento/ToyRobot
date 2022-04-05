#ifndef REQUEST_HANDLER_H_
#define REQUEST_HANDLER_H_

#include <list>

#include "request_type.h"
#include "base_request.h"
#include "base_response.h"

using namespace std;

namespace toyrobot {

class RequestHandler {

public:
    RequestHandler() {}

    ~RequestHandler();

    BaseRequest* CreateRequest(string request_name, int object_id, string data);
    BaseResponse* HandleCommand(BaseRequest* request);

    bool IsPlaceCommand(string command);
    bool IsLeftCommand(string command);
    bool IsRightCommmand(string command);
    bool IsMoveCommand(string command);
    bool IsReportCommand(string command);

private:
    list<pair<BaseRequest*, BaseResponse*>> transactions_;
    Table table;
};

inline bool RequestHandler::IsPlaceCommand(string command) {
    return command == RequestType::kPlaceRequest;
}

inline bool RequestHandler::IsLeftCommand(string command) {
    return command == RequestType::kLeftRequest;
}

inline bool RequestHandler::IsRightCommmand(string command) {
    return command == RequestType::kRightRequest;
}

inline bool RequestHandler::IsMoveCommand(string command) {
    return command == RequestType::kMoveRequest;
}

inline bool RequestHandler::IsReportCommand(string command) {
    return command == RequestType::kReportRequest;
}

} // namespace toyrobot

#endif // REQUEST_HANDLER_H_