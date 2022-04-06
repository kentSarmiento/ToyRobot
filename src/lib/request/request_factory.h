#ifndef REQUEST_FACTORY_H_
#define REQUEST_FACTORY_H_

#include <string>

#include "base_request.h"

using namespace std;

namespace toyrobot {

class RequestFactory {

public:
    static BaseRequest* CreateRequest(const string& request_name, const string& data);
    static BaseRequest* CreateRequest(const string& request_name,
                                      int object_id, const string& data);
    static BaseRequest* CreateRequest(const string& request_name, int object_id);
};

} // namespace toyrobot

#endif // REQUEST_FACTORY_H_