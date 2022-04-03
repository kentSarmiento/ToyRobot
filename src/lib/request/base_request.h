#ifndef REQUEST_BASE_H_
#define REQUEST_BASE_H_

#include <string>

using namespace std;

namespace toyrobot {

class BaseRequest {

public:
    BaseRequest(string name, int id) {
        request_name_ = name;
        object_id_ = id;
        is_valid_ = true;
    }

    string request_name() { return request_name_; }
    int object_id() { return object_id_; }
    bool is_valid() { return is_valid_; }

protected:
    string request_name_;
    int object_id_;
    bool is_valid_;
};

} // namespace toyrobot

#endif // REQUEST_BASE_H_