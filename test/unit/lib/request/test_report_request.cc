#include "catch.hpp"
#include "report_request.h"
#include "place_request.h"

using namespace toyrobot;

TEST_CASE("ReportRequest: Execute requests", "[ReportRequest]") {
    Table table;

    SECTION("Request to report state of a non-existing object") {
        ReportRequest request(0);

        BaseResponse *response = request.Execute(table);

        REQUIRE(request.request_name() == RequestType::kReportRequest);
        REQUIRE(request.is_valid());
        REQUIRE(!request.is_initial_request());
        REQUIRE(request.object_type() == ObjectType::kRobotType);

        REQUIRE(!response);
    }
    SECTION("Request to report state of an object at position (0,0) facing NORTH") {
        PlaceRequest pre_request("0,0,NORTH");
        BaseResponse* response = pre_request.Execute(table);
        delete response;

        ReportRequest request(0);
        response = request.Execute(table);

        REQUIRE(request.request_name() == RequestType::kReportRequest);
        REQUIRE(request.is_valid());
        REQUIRE(!request.is_initial_request());
        REQUIRE(request.object_type() == ObjectType::kRobotType);

        REQUIRE(response);
        delete response;
    }
}