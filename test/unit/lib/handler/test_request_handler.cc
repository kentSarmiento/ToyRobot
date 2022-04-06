#include <iostream>

#include "catch.hpp"
#include "request_handler.h"
#include "request_factory.h"
#include "request_type.h"
#include "base_request.h"
#include "base_response.h"

using namespace std;
using namespace toyrobot;

TEST_CASE("RequestHandler: Create Requests", "[RequestHandler]") {
    RequestHandler request_handler;

    SECTION("Create PLACE Request") {
        BaseRequest *request = request_handler.CreateRequest(RequestType::kPlaceRequest, 0, "0,0,NORTH");

        REQUIRE(request);
        delete request;
    }
    SECTION("Create LEFT Request") {
        BaseRequest *request = request_handler.CreateRequest(RequestType::kLeftRequest, 0, {});

        REQUIRE(request);
        delete request;
    }
    SECTION("Create RIGHT Request") {
        BaseRequest *request = request_handler.CreateRequest(RequestType::kRightRequest, 0, {});

        REQUIRE(request);
        delete request;
    }
    SECTION("Create MOVE Request") {
        BaseRequest *request = request_handler.CreateRequest(RequestType::kMoveRequest, 0, {});

        REQUIRE(request);
        delete request;
    }
    SECTION("Create REPORT Request") {
        BaseRequest *request = request_handler.CreateRequest(RequestType::kReportRequest, 0, {});

        REQUIRE(request);
        delete request;
    }
}

TEST_CASE("RequestHandler: Handle Requests", "[RequestHandler]") {
    RequestHandler request_handler;

    SECTION("Handle PLACE Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, "0,0,NORTH");
        BaseResponse *response = request_handler.HandleCommand(request);
        int object_id;
        response->TakeValue(object_id);

        REQUIRE(response);

        SECTION("Handle REPORT Request") {
            request = RequestFactory::CreateRequest(RequestType::kReportRequest, 0);
            response = request_handler.HandleCommand(request);

            REQUIRE(response);
            string report;
            response->TakeValue(report);

            REQUIRE(report == "0,0,NORTH");
        }
        SECTION("Handle LEFT Request") {
            request = RequestFactory::CreateRequest(RequestType::kLeftRequest, 0);
            response = request_handler.HandleCommand(request);

            REQUIRE(response);
        }
        SECTION("Handle RIGHT Request") {
            request = RequestFactory::CreateRequest(RequestType::kRightRequest, 0);
            response = request_handler.HandleCommand(request);

            REQUIRE(response);
        }
        SECTION("Handle MOVE Request") {
            request = RequestFactory::CreateRequest(RequestType::kMoveRequest, 0);
            response = request_handler.HandleCommand(request);

            REQUIRE(response);
        }
    }
}

TEST_CASE("RequestHandler: Check Command Type", "[RequestHandler]") {
    RequestHandler request_handler;

    SECTION("PLACE Command") {
        REQUIRE(request_handler.IsPlaceCommand(RequestType::kPlaceRequest));
        REQUIRE(!request_handler.IsLeftCommand(RequestType::kPlaceRequest));
        REQUIRE(!request_handler.IsRightCommmand(RequestType::kPlaceRequest));
        REQUIRE(!request_handler.IsMoveCommand(RequestType::kPlaceRequest));
        REQUIRE(!request_handler.IsReportCommand(RequestType::kPlaceRequest));
    }
    SECTION("LEFT Command") {
        REQUIRE(!request_handler.IsPlaceCommand(RequestType::kLeftRequest));
        REQUIRE(request_handler.IsLeftCommand(RequestType::kLeftRequest));
        REQUIRE(!request_handler.IsRightCommmand(RequestType::kLeftRequest));
        REQUIRE(!request_handler.IsMoveCommand(RequestType::kLeftRequest));
        REQUIRE(!request_handler.IsReportCommand(RequestType::kLeftRequest));
    }
    SECTION("RIGHT Command") {
        REQUIRE(!request_handler.IsPlaceCommand(RequestType::kRightRequest));
        REQUIRE(!request_handler.IsLeftCommand(RequestType::kRightRequest));
        REQUIRE(request_handler.IsRightCommmand(RequestType::kRightRequest));
        REQUIRE(!request_handler.IsMoveCommand(RequestType::kRightRequest));
        REQUIRE(!request_handler.IsReportCommand(RequestType::kRightRequest));
    }
    SECTION("MOVE Command") {
        REQUIRE(!request_handler.IsPlaceCommand(RequestType::kMoveRequest));
        REQUIRE(!request_handler.IsLeftCommand(RequestType::kMoveRequest));
        REQUIRE(!request_handler.IsRightCommmand(RequestType::kMoveRequest));
        REQUIRE(request_handler.IsMoveCommand(RequestType::kMoveRequest));
        REQUIRE(!request_handler.IsReportCommand(RequestType::kMoveRequest));
    }
    SECTION("REPORT Command") {
        REQUIRE(!request_handler.IsPlaceCommand(RequestType::kReportRequest));
        REQUIRE(!request_handler.IsLeftCommand(RequestType::kReportRequest));
        REQUIRE(!request_handler.IsRightCommmand(RequestType::kReportRequest));
        REQUIRE(!request_handler.IsMoveCommand(RequestType::kReportRequest));
        REQUIRE(request_handler.IsReportCommand(RequestType::kReportRequest));
    }
}