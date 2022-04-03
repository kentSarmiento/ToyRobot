#include "catch.hpp"
#include "test_robot_object.h"
#include "robot_object.h"

TEST_CASE("RobotObject: Default constructor", "[RobotObject]") {
    TestRobotObject test_robot;

    REQUIRE(test_robot.get_id() == 0);
    REQUIRE(test_robot.get_x_position() == 0);
    REQUIRE(test_robot.get_y_position() == 0);
    REQUIRE(test_robot.get_type() == kRobotType);
    REQUIRE(test_robot.get_facing() == kFacingNorth);
}

TEST_CASE("RobotObject: Complete constructor", "[RobotObject]") {
    TestRobotObject test_robot(1, Coordinates(1,1), kFacingSouth);

    REQUIRE(test_robot.get_id() == 1);
    REQUIRE(test_robot.get_x_position() == 1);
    REQUIRE(test_robot.get_y_position() == 1);
    REQUIRE(test_robot.get_type() == kRobotType);
    REQUIRE(test_robot.get_facing() == kFacingSouth);
}

TEST_CASE("RobotObject: Copy constructor", "[RobotObject]") {
    TestRobotObject test_robot(1, Coordinates(1,1), kFacingSouth);
    TestRobotObject new_robot(test_robot);

    REQUIRE(new_robot.get_id() == 1);
    REQUIRE(new_robot.get_x_position() == 1);
    REQUIRE(new_robot.get_y_position() == 1);
    REQUIRE(new_robot.get_type() == kRobotType);
    REQUIRE(new_robot.get_facing() == kFacingSouth);
}

TEST_CASE("RobotObject: Move Operation", "[RobotObject]") {
    auto x = GENERATE(0, 1, 2, 3, 4);
    auto y = GENERATE(0, 1, 2, 3, 4);

    SECTION("X and Y Coordinate after moving when facing North") {
        TestRobotObject test_robot(1, Coordinates(x,y), kFacingNorth);

        test_robot.Move();

        REQUIRE(test_robot.get_x_position() == x);
        REQUIRE(test_robot.get_y_position() == y+1);
    }
    SECTION("X and Y Coordinate after moving when facing East") {
        TestRobotObject test_robot(1, Coordinates(x,y), kFacingEast);

        test_robot.Move();

        REQUIRE(test_robot.get_x_position() == x+1);
        REQUIRE(test_robot.get_y_position() == y);
    }
    SECTION("X and Y Coordinate after moving when facing South") {
        TestRobotObject test_robot(1, Coordinates(x,y), kFacingSouth);

        test_robot.Move();

        REQUIRE(test_robot.get_x_position() == x);
        REQUIRE(test_robot.get_y_position() == y-1);
    }
    SECTION("X and Y Coordinate after moving when facing West") {
        TestRobotObject test_robot(1, Coordinates(x,y), kFacingWest);

        test_robot.Move();

        REQUIRE(test_robot.get_x_position() == x-1);
        REQUIRE(test_robot.get_y_position() == y);
    }
}
