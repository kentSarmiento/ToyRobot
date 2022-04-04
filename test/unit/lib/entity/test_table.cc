#include "catch.hpp"
#include "test_table.h"
#include "test_base_object.h"
#include "test_robot_object.h"

TEST_CASE("Table: Default constructor", "[Table]") {
    TestTable table;

    REQUIRE(table.get_object_count() == 0);
}

TEST_CASE("Table: Check availability of coordinates", "[Table]") {
    TestTable table;

    SECTION("Free coordinates within table") {
        auto x = GENERATE(0, 1, 2, 3, 4);
        auto y = GENERATE(0, 1, 2, 3, 4);

        REQUIRE(table.IsCoordinatesAvailable(Coordinates(x,y)));
    }

    SECTION("X Coordinate outside of valid range") {
        auto y = GENERATE(0, 1, 2, 3, 4);

        REQUIRE(table.IsCoordinatesAvailable(Coordinates(5,y)) == false);
    }
    SECTION("X Coordinate outside of valid range (negative value)") {
        auto y = GENERATE(0, 1, 2, 3, 4);

        REQUIRE(table.IsCoordinatesAvailable(Coordinates(-1,y)) == false);
    }
    SECTION("Y Coordinate outside of valid range") {
        auto x = GENERATE(0, 1, 2, 3, 4);

        REQUIRE(table.IsCoordinatesAvailable(Coordinates(x,5)) == false);
    }
    SECTION("Y Coordinate outside of valid range (negative value)") {
        auto x = GENERATE(0, 1, 2, 3, 4);

        REQUIRE(table.IsCoordinatesAvailable(Coordinates(x,-1)) == false);
    }

    SECTION("Taken coordinates within table") {
        TestBaseObject *test_object = new TestBaseObject(Coordinates(0,0));
        table.PlaceObject(test_object);

        REQUIRE(table.IsCoordinatesAvailable(Coordinates(0,0)) == false);
    }
}

TEST_CASE("Table: Place Operation", "[Table]") {
    TestTable table;

    SECTION("Place an object") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingSouth);

        int id = table.PlaceObject(test_robot);

        REQUIRE(id != -1);
    }
    SECTION("Place an invalid object") {
        int id = table.PlaceObject(nullptr);

        REQUIRE(id == -1);
    }
}

TEST_CASE("Table: Report status of an object", "[Table]") {
    TestTable table;

    SECTION("Report status of an object") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingNorth);

        int id = table.PlaceObject(test_robot);
        string output = table.ReportObject(id);

        REQUIRE(output == "0,0,NORTH");
    }
}

TEST_CASE("Table: Check availability of coordinates for transfer", "[Table]") {
    TestTable table;
    TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingSouth);

    int id = table.PlaceObject(test_robot);

    SECTION("Free coordinates within table") {
        auto x = GENERATE(1, 2, 3, 4);
        auto y = GENERATE(1, 2, 3, 4);

        REQUIRE(table.IsCoordinatesAvailable(id, Coordinates(x,y)));
    }

    SECTION("Own coordinates within table") {
        REQUIRE(table.IsCoordinatesAvailable(id, Coordinates(0,0)));
    }

    SECTION("X Coordinate outside of valid range") {
        auto y = GENERATE(0, 1, 2, 3, 4);

        REQUIRE(table.IsCoordinatesAvailable(id, Coordinates(5,y)) == false);
    }
    SECTION("X Coordinate outside of valid range (negative value)") {
        auto y = GENERATE(0, 1, 2, 3, 4);

        REQUIRE(table.IsCoordinatesAvailable(id, Coordinates(-1,y)) == false);
    }
    SECTION("Y Coordinate outside of valid range") {
        auto x = GENERATE(0, 1, 2, 3, 4);

        REQUIRE(table.IsCoordinatesAvailable(id, Coordinates(x,5)) == false);
    }
    SECTION("Y Coordinate outside of valid range (negative value)") {
        auto x = GENERATE(0, 1, 2, 3, 4);

        REQUIRE(table.IsCoordinatesAvailable(id, Coordinates(x,-1)) == false);
    }

    SECTION("Taken coordinates within table") {
        TestBaseObject *test_object = new TestBaseObject(Coordinates(1,1));
        table.PlaceObject(test_object);

        REQUIRE(table.IsCoordinatesAvailable(id, Coordinates(1,1)) == false);
    }
}

TEST_CASE("Table: Transfer an object", "[Table]") {
    TestTable table;

    SECTION("Transfer an object") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingSouth);
        int id = table.PlaceObject(test_robot);
        TestRobotObject *new_robot = new TestRobotObject(Coordinates(1,1), kFacingNorth);

        int new_id = table.PlaceObject(id, new_robot);

        REQUIRE(id == new_id);
    }
    SECTION("Transfer an invalid object") {
        int id = table.PlaceObject(0, nullptr);

        REQUIRE(id == -1);
    }
    SECTION("Transfer a new object") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingSouth);
        int id = table.PlaceObject(2, test_robot);

        REQUIRE(id == 0);
    }
}

TEST_CASE("Table: Move an object", "[Table]") {
    TestTable table;

    SECTION("Move an object to North") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(1,1), kFacingNorth);

        int id = table.PlaceObject(test_robot);
        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "1,2,NORTH");
    }
    SECTION("Move an object to East") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(1,1), kFacingEast);

        int id = table.PlaceObject(test_robot);
        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "2,1,EAST");
    }
    SECTION("Move an object to South") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(1,1), kFacingSouth);

        int id = table.PlaceObject(test_robot);
        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "1,0,SOUTH");
    }
    SECTION("Move an object to West") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(1,1), kFacingWest);

        int id = table.PlaceObject(test_robot);
        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "0,1,WEST");
    }
}

TEST_CASE("Table: Move a blocked object", "[Table]") {
    TestTable table;

    SECTION("Move a blocked object to North") {
        TestBaseObject *test_object = new TestBaseObject(Coordinates(2,3));
        table.PlaceObject(test_object);

        TestRobotObject *test_robot = new TestRobotObject(Coordinates(2,2), kFacingNorth);
        int id = table.PlaceObject(test_robot);

        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "2,2,NORTH");
    }
    SECTION("Move a blocked object to East") {
        TestBaseObject *test_object = new TestBaseObject(Coordinates(3,2));
        table.PlaceObject(test_object);

        TestRobotObject *test_robot = new TestRobotObject(Coordinates(2,2), kFacingEast);
        int id = table.PlaceObject(test_robot);

        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "2,2,EAST");
    }
    SECTION("Move a blocked object to South") {
        TestBaseObject *test_object = new TestBaseObject(Coordinates(2,1));
        table.PlaceObject(test_object);

        TestRobotObject *test_robot = new TestRobotObject(Coordinates(2,2), kFacingSouth);
        int id = table.PlaceObject(test_robot);

        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "2,2,SOUTH");
    }
    SECTION("Move a blocked object to West") {
        TestBaseObject *test_object = new TestBaseObject(Coordinates(1,2));
        table.PlaceObject(test_object);

        TestRobotObject *test_robot = new TestRobotObject(Coordinates(2,2), kFacingWest);
        int id = table.PlaceObject(test_robot);

        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "2,2,WEST");
    }
}

TEST_CASE("Table: Move an object in edge", "[Table]") {
    TestTable table;

    SECTION("Move an object in edge to North") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,4), kFacingNorth);

        int id = table.PlaceObject(test_robot);
        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "0,4,NORTH");
    }
    SECTION("Move an object in edge to East") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(4,4), kFacingEast);

        int id = table.PlaceObject(test_robot);
        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "4,4,EAST");
    }
    SECTION("Move an object in edge to South") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(4,0), kFacingSouth);

        int id = table.PlaceObject(test_robot);
        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "4,0,SOUTH");
    }
    SECTION("Move an object in edge to West") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingWest);

        int id = table.PlaceObject(test_robot);
        table.MoveObject(id);

        REQUIRE(table.ReportObject(id) == "0,0,WEST");
    }
}

TEST_CASE("Table: Turn an object to the left", "[Table]") {
    TestTable table;

    SECTION("Turn an object facing North to the left") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingNorth);

        int id = table.PlaceObject(test_robot);
        table.TurnObjectLeft(id);

        REQUIRE(table.ReportObject(id) == "0,0,WEST");
    }
    SECTION("Turn an object facing East to the left") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingEast);

        int id = table.PlaceObject(test_robot);
        table.TurnObjectLeft(id);

        REQUIRE(table.ReportObject(id) == "0,0,NORTH");
    }
    SECTION("Turn an object facing South to the left") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingSouth);

        int id = table.PlaceObject(test_robot);
        table.TurnObjectLeft(id);

        REQUIRE(table.ReportObject(id) == "0,0,EAST");
    }
    SECTION("Turn an object facing West to the left") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingWest);

        int id = table.PlaceObject(test_robot);
        table.TurnObjectLeft(id);

        REQUIRE(table.ReportObject(id) == "0,0,SOUTH");
    }
}

TEST_CASE("Table: Turn an object to the right", "[Table]") {
    TestTable table;

    SECTION("Turn an object facing North to the right") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingNorth);

        int id = table.PlaceObject(test_robot);
        table.TurnObjectRight(id);

        REQUIRE(table.ReportObject(id) == "0,0,EAST");
    }
    SECTION("Turn an object facing East to the right") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingEast);

        int id = table.PlaceObject(test_robot);
        table.TurnObjectRight(id);

        REQUIRE(table.ReportObject(id) == "0,0,SOUTH");
    }
    SECTION("Turn an object facing South to the right") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingSouth);

        int id = table.PlaceObject(test_robot);
        table.TurnObjectRight(id);

        REQUIRE(table.ReportObject(id) == "0,0,WEST");
    }
    SECTION("Turn an object facing West to the right") {
        TestRobotObject *test_robot = new TestRobotObject(Coordinates(0,0), kFacingWest);

        int id = table.PlaceObject(test_robot);
        table.TurnObjectRight(id);

        REQUIRE(table.ReportObject(id) == "0,0,NORTH");
    }
}
