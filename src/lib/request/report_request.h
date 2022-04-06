#ifndef REQUEST_REPORT__H_
#define REQUEST_REPORT__H_

#include "base_request.h"
#include "report_response.h"
#include "request_type.h"

using namespace std;

namespace toyrobot {

class ReportRequest : public BaseRequest {

public:
    ReportRequest(int object_id)
        : BaseRequest(RequestType::kReportRequest, object_id) {}

    BaseResponse* Execute(Table &table) override;
};

inline BaseResponse* ReportRequest::Execute(Table &table) {
    ReportResponse *response = nullptr;
    string report = table.ReportObject(object_id_);
    if (!report.empty())
        response = new ReportResponse(report);
    return response;
}

} // namespace toyrobot

#endif // REQUEST_REPORT__H_