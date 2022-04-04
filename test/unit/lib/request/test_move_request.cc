#include "catch.hpp"
#include "move_request.h"

using namespace toyrobot;

TEST_CASE("MoveRequest: Execute requests", "[MoveRequest]") {
    Table table;

    SECTION("Request to move an object") {
        MoveRequest request(0);

        BaseResponse* response = request.Execute(table);

        REQUIRE(request.request_name() == RequestType::kMoveRequest);
        REQUIRE(request.is_valid());
        REQUIRE(!request.is_initial_request());
        REQUIRE(request.object_type() == ObjectType::kRobotType);

        REQUIRE(response);
        delete response;
    }
}