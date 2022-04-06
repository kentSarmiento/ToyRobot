#ifndef RESPONSE_BASE_H_
#define RESPONSE_BASE_H_

#include <string>

using namespace std;

namespace toyrobot {

class BaseResponse {

public:
    explicit BaseResponse(const string& request_name)
        : request_name_(request_name) {}

    virtual ~BaseResponse() = default;

    string request_name() { return request_name_; }

    virtual void TakeValue(string &value) { value = {}; }
    virtual void TakeValue(int &value) { value = 0; }

protected:
    string request_name_;
};

} // namespace toyrobot

#endif // RESPONSE_BASE_H_