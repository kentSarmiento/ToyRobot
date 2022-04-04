#include <sstream>

#include "catch.hpp"
#include "test_robot_object.h"
#include "robot_object.h"

using namespace std;

TEST_CASE("RobotObject: Default constructor", "[RobotObject]") {
    TestRobotObject test_robot;

    REQUIRE(test_robot.id() == 0);
    REQUIRE(test_robot.x_position() == 0);
    REQUIRE(test_robot.y_position() == 0);
    REQUIRE(test_robot.type() == kRobotType);
    REQUIRE(test_robot.facing().value() == Direction::kNorth);
}

TEST_CASE("RobotObject: Complete constructor", "[RobotObject]") {
    TestRobotObject test_robot(Coordinates(1,1), Direction(Direction::kSouth));

    REQUIRE(test_robot.id() == 0);
    REQUIRE(test_robot.x_position() == 1);
    REQUIRE(test_robot.y_position() == 1);
    REQUIRE(test_robot.type() == kRobotType);
    REQUIRE(test_robot.facing().value() == Direction::kSouth);
}

TEST_CASE("RobotObject: Copy constructor", "[RobotObject]") {
    TestRobotObject test_robot(Coordinates(1,1), Direction(Direction::kSouth));
    TestRobotObject new_robot(test_robot);

    REQUIRE(new_robot.id() == 0);
    REQUIRE(new_robot.x_position() == 1);
    REQUIRE(new_robot.y_position() == 1);
    REQUIRE(new_robot.type() == kRobotType);
    REQUIRE(test_robot.facing().value() == Direction::kSouth);
}

TEST_CASE("RobotObject: Move Operation", "[RobotObject]") {
    auto x = GENERATE(0, 1, 2, 3, 4);
    auto y = GENERATE(0, 1, 2, 3, 4);

    SECTION("X and Y Coordinate after moving when facing North") {
        TestRobotObject test_robot(Coordinates(x,y), Direction(Direction::kNorth));

        test_robot.Move();

        REQUIRE(test_robot.x_position() == x);
        REQUIRE(test_robot.y_position() == y+1);
    }
    SECTION("X and Y Coordinate after moving when facing East") {
        TestRobotObject test_robot(Coordinates(x,y), Direction(Direction::kEast));

        test_robot.Move();

        REQUIRE(test_robot.x_position() == x+1);
        REQUIRE(test_robot.y_position() == y);
    }
    SECTION("X and Y Coordinate after moving when facing South") {
        TestRobotObject test_robot(Coordinates(x,y), Direction(Direction::kSouth));

        test_robot.Move();

        REQUIRE(test_robot.x_position() == x);
        REQUIRE(test_robot.y_position() == y-1);
    }
    SECTION("X and Y Coordinate after moving when facing West") {
        TestRobotObject test_robot(Coordinates(x,y), Direction(Direction::kWest));

        test_robot.Move();

        REQUIRE(test_robot.x_position() == x-1);
        REQUIRE(test_robot.y_position() == y);
    }
}

TEST_CASE("RobotObject: Turn Left Operation", "[RobotObject]") {

    SECTION("Direction facing after turning left when facing North") {
        TestRobotObject test_robot(Coordinates(0,0), Direction(Direction::kNorth));

        test_robot.TurnLeft();

        REQUIRE(test_robot.facing().value() == Direction::kWest);
    }
    SECTION("Direction facing after turning left when facing East") {
        TestRobotObject test_robot(Coordinates(0,0), Direction(Direction::kEast));

        test_robot.TurnLeft();

        REQUIRE(test_robot.facing().value() == Direction::kNorth);
    }
    SECTION("Direction facing after turning left when facing South") {
        TestRobotObject test_robot(Coordinates(0,0), Direction(Direction::kSouth));

        test_robot.TurnLeft();

        REQUIRE(test_robot.facing().value() == Direction::kEast);
    }
    SECTION("Direction facing after turning left when facing West") {
        TestRobotObject test_robot(Coordinates(0,0), Direction(Direction::kWest));

        test_robot.TurnLeft();

        REQUIRE(test_robot.facing().value() == Direction::kSouth);
    }
}

TEST_CASE("RobotObject: Turn Right Operation", "[RobotObject]") {

    SECTION("Direction facing after turning right when facing North") {
        TestRobotObject test_robot(Coordinates(0,0), Direction(Direction::kNorth));

        test_robot.TurnRight();

        REQUIRE(test_robot.facing().value() == Direction::kEast);
    }
    SECTION("Direction facing after turning left when facing East") {
        TestRobotObject test_robot(Coordinates(0,0), Direction(Direction::kEast));

        test_robot.TurnRight();

        REQUIRE(test_robot.facing().value() == Direction::kSouth);
    }
    SECTION("Direction facing after turning left when facing South") {
        TestRobotObject test_robot(Coordinates(0,0), Direction(Direction::kSouth));

        test_robot.TurnRight();

        REQUIRE(test_robot.facing().value() == Direction::kWest);
    }
    SECTION("Direction facing after turning left when facing West") {
        TestRobotObject test_robot(Coordinates(0,0), Direction(Direction::kWest));

        test_robot.TurnRight();

        REQUIRE(test_robot.facing().value() == Direction::kNorth);
    }
}

TEST_CASE("RobotObject: Report Operation", "[RobotObject]") {
    auto x = GENERATE(0, 1, 2, 3, 4);
    auto y = GENERATE(0, 1, 2, 3, 4);

    SECTION("Report status at position (X,Y) and facing North") {
        TestRobotObject test_robot(Coordinates(x,y), Direction(Direction::kNorth));
        stringstream expected_report;
        expected_report << x << "," << y << "," << "NORTH";

        string report = test_robot.Report();

        REQUIRE(report == expected_report.str());
    }
    SECTION("Report status at position (X,Y) and facing East") {
        TestRobotObject test_robot(Coordinates(x,y), Direction(Direction::kEast));
        stringstream expected_report;
        expected_report << x << "," << y << "," << "EAST";

        string report = test_robot.Report();

        REQUIRE(report == expected_report.str());
    }
    SECTION("Report status at position (X,Y) and facing South") {
        TestRobotObject test_robot(Coordinates(x,y), Direction(Direction::kSouth));
        stringstream expected_report;
        expected_report << x << "," << y << "," << "SOUTH";

        string report = test_robot.Report();

        REQUIRE(report == expected_report.str());
    }
    SECTION("Report status at position (X,Y) and facing West") {
        TestRobotObject test_robot(Coordinates(x,y), Direction(Direction::kWest));
        stringstream expected_report;
        expected_report << x << "," << y << "," << "WEST";

        string report = test_robot.Report();

        REQUIRE(report == expected_report.str());
    }
}
