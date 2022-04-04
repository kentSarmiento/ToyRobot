#include "request_handler.h"
#include "base_request.h"
#include "base_response.h"
#include "table.h"

namespace toyrobot {

BaseResponse* RequestHandler::HandleCommand(BaseRequest* request) {
    static Table table;
    BaseResponse *response = nullptr;

    if (request && request->is_valid()) {
        response = request->Execute(table);
    }

    return response;
}

} // namespace toyrobot