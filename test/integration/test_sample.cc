#include "catch.hpp"


SCENARIO("Sample scenarios", "[sample]") {

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {

        WHEN("Robot is moved") {

            THEN("Robot is now located at (0,1) facing NORTH") {

            }
        }
    }

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {

        WHEN("Robot is turned left") {

            THEN("Robot is now located at (0,0) facing WEST") {

            }
        }
    }

    GIVEN("A table with a Robot placed at (1,2) facing EAST") {

        WHEN("Robot is moved, moved, turned left, moved") {

            THEN("Robot is now located at (3,3) facing NORTH") {

            }
        }
    }
}