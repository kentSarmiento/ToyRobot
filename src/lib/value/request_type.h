#ifndef VALUE_REQUEST_TYPE_H_
#define VALUE_REQUEST_TYPE_H_

#include <string>
using namespace std;

namespace toyrobot {

class RequestType {

public:
    static const string kPlaceRequest;
    static const string kLeftRequest;
    static const string kRightRequest;
    static const string kMoveRequest;
    static const string kReportRequest;
};

} // namespace toyrobot

#endif // VALUE_REQUEST_TYPE_H_