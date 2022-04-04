#include "request_factory.h"
#include "base_request.h"
#include "place_request.h"
#include "left_request.h"
#include "right_request.h"
#include "move_request.h"
#include "report_request.h"
#include "request_type.h"

namespace toyrobot {

BaseRequest* RequestFactory::CreateRequest(string request_name, string data) {
    BaseRequest* request = nullptr;
    if (request_name == RequestType::kPlaceRequest) {
        request = new PlaceRequest(data);
    }
    return request;
}

BaseRequest* RequestFactory::CreateRequest(string request_name, int object_id, string data) {
    BaseRequest* request = nullptr;
    if (request_name == RequestType::kPlaceRequest) {
        request = new PlaceRequest(object_id, data);
    }
    return request;
}

BaseRequest* RequestFactory::CreateRequest(string request_name, int object_id) {
    BaseRequest* request = nullptr;
    if (request_name == RequestType::kLeftRequest) {
        request = new LeftRequest(object_id);
    } else if (request_name == RequestType::kRightRequest) {
        request = new RightRequest(object_id);
    } else if (request_name == RequestType::kMoveRequest) {
        request = new MoveRequest(object_id);
    } else if (request_name == RequestType::kReportRequest) {
        request = new ReportRequest(object_id);
    }
    return request;
}

} // namespace toyrobot