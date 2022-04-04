#include "catch.hpp"
#include "base_response.h"

using namespace toyrobot;

TEST_CASE("BaseResponse: Take Value", "[BaseResponse]") {

    SECTION("Take values from response") {
        BaseResponse response({});

        string s_value;
        int i_value;

        response.TakeValue(s_value);
        response.TakeValue(i_value);

        REQUIRE(s_value.empty());
        REQUIRE(i_value == 0);
    }
}