#ifndef RESPONSE_REPORT_H_
#define RESPONSE_REPORT_H_

#include <string>

#include "base_response.h"
#include "request_type.h"

using namespace std;

namespace toyrobot {

class ReportResponse : public BaseResponse {

public:
    ReportResponse(const string& report)
        : BaseResponse(RequestType::kReportRequest) {
        report_ = report;
    }

    void TakeValue(string &value) override;

protected:
    string report_;
};

inline void ReportResponse::TakeValue(string &value) {
    value = report_;
}

} // namespace toyrobot

#endif // RESPONSE_REPORT_H_