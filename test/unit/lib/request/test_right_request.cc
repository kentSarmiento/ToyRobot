#include "catch.hpp"
#include "right_request.h"

using namespace toyrobot;

TEST_CASE("RightRequest: Execute requests", "[RightRequest]") {
    Table table;

    SECTION("Request to turn an object to the right") {
        RightRequest request(0);

        BaseResponse* response = request.Execute(table);

        REQUIRE(request.request_name() == RequestType::kRightRequest);
        REQUIRE(request.is_valid());
        REQUIRE(!request.is_initial_request());
        REQUIRE(request.object_type() == ObjectType::kRobotType);

        REQUIRE(response);
        delete response;
    }
}