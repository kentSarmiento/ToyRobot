#include <sstream>

#include "catch.hpp"
#include "test_robot_object.h"
#include "robot_object.h"

using namespace std;

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

TEST_CASE("RobotObject: Turn Left Operation", "[RobotObject]") {

    SECTION("Direction facing after turning left when facing North") {
        TestRobotObject test_robot(1, Coordinates(0,0), kFacingNorth);

        test_robot.TurnLeft();

        REQUIRE(test_robot.get_facing() == kFacingWest);
    }
    SECTION("Direction facing after turning left when facing East") {
        TestRobotObject test_robot(1, Coordinates(0,0), kFacingEast);

        test_robot.TurnLeft();

        REQUIRE(test_robot.get_facing() == kFacingNorth);
    }
    SECTION("Direction facing after turning left when facing South") {
        TestRobotObject test_robot(1, Coordinates(0,0), kFacingSouth);

        test_robot.TurnLeft();

        REQUIRE(test_robot.get_facing() == kFacingEast);
    }
    SECTION("Direction facing after turning left when facing West") {
        TestRobotObject test_robot(1, Coordinates(0,0), kFacingWest);

        test_robot.TurnLeft();

        REQUIRE(test_robot.get_facing() == kFacingSouth);
    }
}

TEST_CASE("RobotObject: Turn Right Operation", "[RobotObject]") {

    SECTION("Direction facing after turning right when facing North") {
        TestRobotObject test_robot(1, Coordinates(0,0), kFacingNorth);

        test_robot.TurnRight();

        REQUIRE(test_robot.get_facing() == kFacingEast);
    }
    SECTION("Direction facing after turning left when facing East") {
        TestRobotObject test_robot(1, Coordinates(0,0), kFacingEast);

        test_robot.TurnRight();

        REQUIRE(test_robot.get_facing() == kFacingSouth);
    }
    SECTION("Direction facing after turning left when facing South") {
        TestRobotObject test_robot(1, Coordinates(0,0), kFacingSouth);

        test_robot.TurnRight();

        REQUIRE(test_robot.get_facing() == kFacingWest);
    }
    SECTION("Direction facing after turning left when facing West") {
        TestRobotObject test_robot(1, Coordinates(0,0), kFacingWest);

        test_robot.TurnRight();

        REQUIRE(test_robot.get_facing() == kFacingNorth);
    }
}

TEST_CASE("RobotObject: Report Operation", "[RobotObject]") {
    auto x = GENERATE(0, 1, 2, 3, 4);
    auto y = GENERATE(0, 1, 2, 3, 4);

    SECTION("Report status at position (X,Y) and facing North") {
        TestRobotObject test_robot(1, Coordinates(x,y), kFacingNorth);
        stringstream expected_report;
        expected_report << x << "," << y << "," << "NORTH";

        string report = test_robot.Report();

        REQUIRE(report == expected_report.str());
    }
    SECTION("Report status at position (X,Y) and facing East") {
        TestRobotObject test_robot(1, Coordinates(x,y), kFacingEast);
        stringstream expected_report;
        expected_report << x << "," << y << "," << "EAST";

        string report = test_robot.Report();

        REQUIRE(report == expected_report.str());
    }
    SECTION("Report status at position (X,Y) and facing South") {
        TestRobotObject test_robot(1, Coordinates(x,y), kFacingSouth);
        stringstream expected_report;
        expected_report << x << "," << y << "," << "SOUTH";

        string report = test_robot.Report();

        REQUIRE(report == expected_report.str());
    }
    SECTION("Report status at position (X,Y) and facing West") {
        TestRobotObject test_robot(1, Coordinates(x,y), kFacingWest);
        stringstream expected_report;
        expected_report << x << "," << y << "," << "WEST";

        string report = test_robot.Report();

        REQUIRE(report == expected_report.str());
    }
}
