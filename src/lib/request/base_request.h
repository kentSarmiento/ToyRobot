#ifndef REQUEST_BASE_H_
#define REQUEST_BASE_H_

#include <string>

#include "base_response.h"
#include "table.h"

using namespace std;

namespace toyrobot {

class BaseRequest {

public:
    BaseRequest(string request_name, int object_id) {
        request_name_ = request_name;
        object_id_ = object_id;
        is_valid_ = true;
    }

    BaseResponse* Execute(Table &table);

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