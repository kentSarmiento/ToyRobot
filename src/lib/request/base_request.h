#ifndef REQUEST_BASE_H_
#define REQUEST_BASE_H_

#include <string>

#include "base_response.h"
#include "object_type.h"
#include "table.h"

using namespace std;

namespace toyrobot {

class BaseRequest {

public:
    BaseRequest(const string& request_name) {
        request_name_ = request_name;
        object_type_ = ObjectType::kRobotType;
        is_valid_ = true;
        is_initial_request_ = true;
    }

    BaseRequest(const string& request_name, int object_id) {
        request_name_ = request_name;
        object_type_ = ObjectType::kRobotType;
        object_id_ = object_id;
        is_valid_ = true;
        is_initial_request_ = false;
    }

    virtual ~BaseRequest() = default;

    virtual BaseResponse* Execute(Table &table) = 0;

    string request_name() { return request_name_; }
    ObjectType object_type() { return object_type_; }
    int object_id() { return object_id_; }
    bool is_valid() { return is_valid_; }
    bool is_initial_request() { return is_initial_request_; }

protected:
    string request_name_;
    ObjectType object_type_;
    int object_id_;
    bool is_valid_;
    bool is_initial_request_;
};

} // namespace toyrobot

#endif // REQUEST_BASE_H_