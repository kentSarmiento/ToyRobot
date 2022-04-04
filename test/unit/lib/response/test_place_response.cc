#include "catch.hpp"
#include "place_response.h"

using namespace toyrobot;

TEST_CASE("PlaceResponse: Take Value", "[PlaceResponse]") {

    SECTION("Take values from response") {
        PlaceResponse response(1);

        int i_value;
        response.TakeValue(i_value);

        REQUIRE(i_value == 1);
    }
}