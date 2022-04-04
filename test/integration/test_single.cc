#include <iostream>

#include "catch.hpp"
#include "request_handler.h"
#include "request_factory.h"
#include "base_response.h"
#include "request_type.h"

using namespace std;
using namespace toyrobot;

SCENARIO("Placing robot", "[adding]") {
    int object_id = 0;

    GIVEN("A table with a pre-defined size (5x5)") {

        WHEN("A Robot is placed at (0,0) facing NORTH") {
            BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "0,0,NORTH");
            BaseResponse *response = RequestHandler::HandleCommand(request);

            THEN("A Robot is added to the Table") {
                REQUIRE(response);

                response->TakeValue(object_id);
                REQUIRE(object_id == 0);
            }
        }
    }

    GIVEN("A table with a pre-defined size (5x5)") {

        WHEN("A Robot is placed at (5,5) facing NORTH") {
            BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, "5,5,NORTH");
            BaseResponse *response = RequestHandler::HandleCommand(request);

            THEN("A Robot is not added to the Table") {
                REQUIRE(!response);
            }
        }
    }
}

SCENARIO("Reporting robot state", "[report]") {
    int object_id = 0;

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "0,0,NORTH");
        RequestHandler::HandleCommand(request);

        WHEN("A Robot is made to report its State") {
            request = RequestFactory::CreateRequest(RequestType::kReportRequest, object_id);
            BaseResponse *response = RequestHandler::HandleCommand(request);

            THEN("A Robot is able to report its location at (0,0) and direction facing NORTH") {
                string report;
                response->TakeValue(report);
                REQUIRE(report == "0,0,NORTH");
            }
        }
    }
}

SCENARIO("Transferring robot", "[transfer]") {
    int object_id = 0;

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "0,0,NORTH");
        RequestHandler::HandleCommand(request);

        WHEN("A Robot is placed at (1,1) facing SOUTH") {
            request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "1,1,SOUTH");
            BaseResponse *response = RequestHandler::HandleCommand(request);
            int new_object_id;
            response->TakeValue(new_object_id);

            THEN("Robot is now located at (1,1) facing SOUTH") {
                REQUIRE(new_object_id == object_id);

                request = RequestFactory::CreateRequest(RequestType::kReportRequest, object_id);
                response = RequestHandler::HandleCommand(request);
                string report;
                response->TakeValue(report);
                REQUIRE(report == "1,1,SOUTH");
            }
        }
    }

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "0,0,NORTH");
        RequestHandler::HandleCommand(request);

        WHEN("A Robot is place at (5,5) facing SOUTH") {
            request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "5,5,SOUTH");
            RequestHandler::HandleCommand(request);

            THEN("Robot is still located at (0,0) facing NORTH") {
                request = RequestFactory::CreateRequest(RequestType::kReportRequest, object_id);
                BaseResponse *response = RequestHandler::HandleCommand(request);
                string report;
                response->TakeValue(report);
                REQUIRE(report == "0,0,NORTH");
            }
        }
    }
}

SCENARIO("Turning robot", "[turn]") {
    int object_id = 0;

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "0,0,NORTH");
        RequestHandler::HandleCommand(request);

        WHEN("Robot is turned left") {
            request = RequestFactory::CreateRequest(RequestType::kLeftRequest, object_id);
            RequestHandler::HandleCommand(request);

            THEN("Robot is now located at (0,0) facing WEST") {
                request = RequestFactory::CreateRequest(RequestType::kReportRequest, object_id);
                BaseResponse *response = RequestHandler::HandleCommand(request);
                string report;
                response->TakeValue(report);
                REQUIRE(report == "0,0,WEST");
            }
        }
    }

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "0,0,NORTH");
        RequestHandler::HandleCommand(request);

        WHEN("Robot is turned right") {
            request = RequestFactory::CreateRequest(RequestType::kRightRequest, object_id);
            RequestHandler::HandleCommand(request);

            THEN("Robot is now located at (0,0) facing EAST") {
                request = RequestFactory::CreateRequest(RequestType::kReportRequest, object_id);
                BaseResponse *response = RequestHandler::HandleCommand(request);
                string report;
                response->TakeValue(report);
                REQUIRE(report == "0,0,EAST");
            }
        }
    }
}

SCENARIO("Moving robot", "[move]") {
    int object_id = 0;

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "0,0,NORTH");
        RequestHandler::HandleCommand(request);

        WHEN("Robot is moved") {
            request = RequestFactory::CreateRequest(RequestType::kMoveRequest, object_id);
            RequestHandler::HandleCommand(request);

            THEN("Robot is now located at (0,1) facing NORTH") {
                request = RequestFactory::CreateRequest(RequestType::kReportRequest, object_id);
                BaseResponse *response = RequestHandler::HandleCommand(request);
                string report;
                response->TakeValue(report);
                REQUIRE(report == "0,1,NORTH");
            }
        }
    }

    GIVEN("A table with a Robot placed at (0,4) facing EAST") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "0,4,EAST");
        RequestHandler::HandleCommand(request);

        WHEN("Robot is moved") {
            request = RequestFactory::CreateRequest(RequestType::kMoveRequest, object_id);
            RequestHandler::HandleCommand(request);

            THEN("Robot is now located at (1,4) facing EAST") {
                request = RequestFactory::CreateRequest(RequestType::kReportRequest, object_id);
                BaseResponse *response = RequestHandler::HandleCommand(request);
                string report;
                response->TakeValue(report);
                REQUIRE(report == "1,4,EAST");
            }
        }
    }

    GIVEN("A table with a Robot placed at (4,4) facing SOUTH") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "4,4,SOUTH");
        RequestHandler::HandleCommand(request);

        WHEN("Robot is moved") {
            request = RequestFactory::CreateRequest(RequestType::kMoveRequest, object_id);
            RequestHandler::HandleCommand(request);

            THEN("Robot is still located at (4,3) facing SOUTH") {
                request = RequestFactory::CreateRequest(RequestType::kReportRequest, object_id);
                BaseResponse *response = RequestHandler::HandleCommand(request);
                string report;
                response->TakeValue(report);
                REQUIRE(report == "4,3,SOUTH");
            }
        }
    }

    GIVEN("A table with a Robot placed at (4,0) facing WEST") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "4,0,WEST");
        RequestHandler::HandleCommand(request);

        WHEN("Robot is moved") {
            request = RequestFactory::CreateRequest(RequestType::kMoveRequest, object_id);
            RequestHandler::HandleCommand(request);

            THEN("Robot is still located at (3,0) facing WEST") {
                request = RequestFactory::CreateRequest(RequestType::kReportRequest, object_id);
                BaseResponse *response = RequestHandler::HandleCommand(request);
                string report;
                response->TakeValue(report);
                REQUIRE(report == "3,0,WEST");
            }
        }
    }
}

SCENARIO("Sample scenarios", "[sample]") {
    int object_id = 0;

    GIVEN("A table with a Robot placed at (1,2) facing EAST") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, object_id, "1,2,EAST");
        RequestHandler::HandleCommand(request);

        WHEN("Robot is moved, moved, turned left, moved") {
            request = RequestFactory::CreateRequest(RequestType::kMoveRequest, object_id);
            RequestHandler::HandleCommand(request);
            request = RequestFactory::CreateRequest(RequestType::kMoveRequest, object_id);
            RequestHandler::HandleCommand(request);
            request = RequestFactory::CreateRequest(RequestType::kLeftRequest, object_id);
            RequestHandler::HandleCommand(request);
            request = RequestFactory::CreateRequest(RequestType::kMoveRequest, object_id);
            RequestHandler::HandleCommand(request);

            THEN("Robot is now located at (3,3) facing NORTH") {
                request = RequestFactory::CreateRequest(RequestType::kReportRequest, object_id);
                BaseResponse *response = RequestHandler::HandleCommand(request);
                string report;
                response->TakeValue(report);
                REQUIRE(report == "3,3,NORTH");
            }
        }
    }
}