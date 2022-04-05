#include <iostream>
#include <sstream>

#include "request_handler.h"
#include "request_factory.h"
#include "request_type.h"

using namespace std;
using namespace toyrobot;

int main() {
    RequestHandler request_handler;
    int robot_id = -1;

    while (1) {
        string request_name;
        string request_data;

        cin >> request_name;

        BaseRequest *request;
        if (request_name == RequestType::kPlaceRequest) {
            cin >> request_data;
            request = RequestFactory::CreateRequest(request_name, robot_id, request_data);
        } else {
            request = RequestFactory::CreateRequest(request_name, robot_id);
        }

        if (request) {
            BaseResponse *response = request_handler.HandleCommand(request);

            if (response) {
                if (request_name == RequestType::kPlaceRequest) {
                    response->TakeValue(robot_id);
                } else if (request_name == RequestType::kReportRequest) {
                    string report;
                    response ->TakeValue(report);
                    cout << "Output: " << report << endl;
                }
            }
        }
    }

    return 0;
}
