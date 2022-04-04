#include "catch.hpp"
#include "report_request.h"

using namespace toyrobot;

TEST_CASE("ReportRequest: Execute requests", "[ReportRequest]") {
    Table table;

    SECTION("Request to report state of an object at position (0,0) facing NORTH") {
        ReportRequest request(0);

        BaseResponse *response = request.Execute(table);

        REQUIRE(request.request_name() == RequestType::kReportRequest);
        REQUIRE(request.is_valid());
        REQUIRE(!request.is_initial_request());
        REQUIRE(request.object_type() == ObjectType::kRobotType);

        REQUIRE(response);
        delete response;
    }
}