#include "catch.hpp"
#include "left_request.h"

using namespace toyrobot;

TEST_CASE("LeftRequest: Execute requests", "[LeftRequest]") {
    Table table;

    SECTION("Request to turn an object to the left") {
        LeftRequest request(0);

        BaseResponse* response = request.Execute(table);

        REQUIRE(request.request_name() == RequestType::kLeftRequest);
        REQUIRE(request.is_valid());
        REQUIRE(!request.is_initial_request());
        REQUIRE(request.object_type() == ObjectType::kRobotType);

        REQUIRE(response);
        delete response;
    }
}