#include "request_handler.h"
#include "request_factory.h"
#include "table.h"

namespace toyrobot {

RequestHandler::~RequestHandler() {
    for (auto it : transactions_) {
        if (it.first) delete it.first;
        if (it.second) delete it.second;
    }
}

BaseRequest* RequestHandler::CreateRequest(const string& request_name,
                                           int object_id, string data) {
    BaseRequest *request;

    if (request_name == RequestType::kPlaceRequest) {
        request = RequestFactory::CreateRequest(request_name, object_id, data);
    } else {
        request = RequestFactory::CreateRequest(request_name, object_id);
    }

    return request;
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