#include "request_handler.h"
#include "base_request.h"
#include "base_response.h"
#include "table.h"

namespace toyrobot {

RequestHandler::~RequestHandler() {
    for (auto it : transactions_) {
        if (it.first) delete it.first;
        if (it.second) delete it.second;
    }
}

BaseResponse* RequestHandler::HandleCommand(BaseRequest* request) {
    BaseResponse *response = nullptr;

    if (request && request->is_valid()) {
        response = request->Execute(table);
    }
    transactions_.push_back(pair<BaseRequest*, BaseResponse*>(request, response));

    return response;
}

} // namespace toyrobot