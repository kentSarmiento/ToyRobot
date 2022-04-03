#include "catch.hpp"
#include "base_request.h"

using namespace toyrobot;

TEST_CASE("BaseRequest: Default constructor", "[BaseRequest]") {
    BaseRequest request("request", 1);

    REQUIRE(request.request_name() == "request");
    REQUIRE(request.object_id() == 1);
    REQUIRE(request.is_valid());
}