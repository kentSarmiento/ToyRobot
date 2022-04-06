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

    BaseRequest* CreateRequest(const string& request_name,
                               int object_id, string data);
    BaseResponse* HandleCommand(BaseRequest* request);

    bool IsPlaceCommand(const string& command);
    bool IsLeftCommand(const string& command);
    bool IsRightCommmand(const string& command);
    bool IsMoveCommand(const string& command);
    bool IsReportCommand(const string& command);

private:
    list<pair<BaseRequest*, BaseResponse*>> transactions_;
    Table table;
};

inline bool RequestHandler::IsPlaceCommand(const string& command) {
    return command == RequestType::kPlaceRequest;
}

inline bool RequestHandler::IsLeftCommand(const string& command) {
    return command == RequestType::kLeftRequest;
}

inline bool RequestHandler::IsRightCommmand(const string& command) {
    return command == RequestType::kRightRequest;
}

inline bool RequestHandler::IsMoveCommand(const string& command) {
    return command == RequestType::kMoveRequest;
}

inline bool RequestHandler::IsReportCommand(const string& command) {
    return command == RequestType::kReportRequest;
}

} // namespace toyrobot

#endif // REQUEST_HANDLER_H_