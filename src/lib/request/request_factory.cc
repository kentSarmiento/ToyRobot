#include "request_factory.h"
#include "base_request.h"
#include "place_request.h"
#include "request_type.h"

namespace toyrobot {

BaseRequest* RequestFactory::CreateRequest(string request_name, int object_id, string args) {
    if (request_name == RequestType::kPlaceRequest) {
        return new PlaceRequest(object_id, args);
    } else if (request_name == RequestType::kLeftRequest) {
        return new BaseRequest(request_name, object_id);
    } else if (request_name == RequestType::kRightRequest) {
        return new BaseRequest(request_name, object_id);
    } else if (request_name == RequestType::kMoveRequest) {
        return new BaseRequest(request_name, object_id);
    } else if (request_name == RequestType::kReportRequest) {
        return new BaseRequest(request_name, object_id);
    } else {
        return nullptr;
    }
}

} // namespace toyrobot