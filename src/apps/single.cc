#include <iostream>
#include <sstream>

#include "request_handler.h"
#include "request_factory.h"
#include "request_type.h"

using namespace std;
using namespace toyrobot;

int main() {
    int robot_id = -1;

    while (1) {
        string command_name;
        string data;

        cin >> command_name;

        BaseRequest *command;
        if (command_name == RequestType::kPlaceRequest) {
            cin >> data;
            command = RequestFactory::CreateRequest(command_name, robot_id, data);
        } else {
            command = RequestFactory::CreateRequest(command_name, robot_id);
        }

        if (command) {
            BaseResponse *response = RequestHandler::HandleCommand(command);

            if (response) {
                if (command_name == RequestType::kPlaceRequest) {
                    response->TakeValue(robot_id);
                } else if (command_name == RequestType::kReportRequest) {
                    string report;
                    response ->TakeValue(report);
                    cout << "Output: " << report << endl;
                }
            }
        }
    }

    return 0;
}
