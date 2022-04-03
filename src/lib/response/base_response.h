#ifndef RESPONSE_BASE_H_
#define RESPONSE_BASE_H_

#include <string>

using namespace std;

namespace toyrobot {

class BaseResponse {

public:
    BaseResponse(string request_name, int object_id) {
        request_name_ = request_name;
        object_id_ = object_id;
    }

    string request_name() { return request_name_; }
    int object_id() { return object_id_; }

protected:
    string request_name_;
    int object_id_;
};

} // namespace toyrobot

#endif // RESPONSE_BASE_H_