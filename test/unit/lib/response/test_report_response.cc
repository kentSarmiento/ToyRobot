#include "catch.hpp"
#include "report_response.h"

using namespace toyrobot;

TEST_CASE("ReportResponse: Take Value", "[ReportResponse]") {

    SECTION("Take values from response") {
        string report = "1,1,NORTH";
        ReportResponse response(report);

        string s_value;
        response.TakeValue(s_value);

        REQUIRE(s_value == report);
    }
}