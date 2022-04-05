#include <iostream>
#include <sstream>

#include "request_handler.h"

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

        if (request_handler.IsPlaceCommand(request_name))
            cin >> request_data;

        request = request_handler.CreateRequest(request_name, robot_id, request_data);

        if (request) {
            BaseResponse *response = request_handler.HandleCommand(request);

            if (response) {
                if (request_handler.IsPlaceCommand(request_name)) {
                    response->TakeValue(robot_id);
                } else if (request_handler.IsReportCommand(request_name)) {
                    string report;
                    response ->TakeValue(report);
                    cout << "Output: " << report << endl;
                }
            }
        }
    }

    return 0;
}
