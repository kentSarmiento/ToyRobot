#include "catch.hpp"
#include "test_table.h"

TEST_CASE("Table: Default constructor", "[Table]") {
    TestTable table;

    REQUIRE(table.get_object_count() == 0);
}

TEST_CASE("Table: Check validity of coordinates", "[Table]") {

    SECTION("Valid coordinates within table") {
    }
    SECTION("X Coordinate outside of valid range") {
    }
    SECTION("X Coordinate outside of valid range (negative value)") {
    }
    SECTION("Y Coordinate outside of valid range") {
    }
    SECTION("Y Coordinate outside of valid range (negative value)") {
    }
}

TEST_CASE("Table: Place Operation", "[Table]") {

    SECTION("Place an object") {
    }
    SECTION("Place an invalid object") {
    }
}

TEST_CASE("Table: Report status of an object", "[Table]") {

    SECTION("Report status of an object") {
    }
}

TEST_CASE("Table: Transfer place of an object", "[Table]") {

    SECTION("Transfer an object") {
    }
    SECTION("Transfer an invalid object") {
    }
}

TEST_CASE("Table: Move an object", "[Table]") {

    SECTION("Move an object to North") {
    }
    SECTION("Move an object to East") {
    }
    SECTION("Move an object to South") {
    }
    SECTION("Move an object to West") {
    }
}

TEST_CASE("Table: Move a blocked object", "[Table]") {

    SECTION("Move a blocked object to North") {
    }
    SECTION("Move a blocked object to East") {
    }
    SECTION("Move a blocked object to South") {
    }
    SECTION("Move a blocked object to West") {
    }
}

TEST_CASE("Table: Move an object in edge", "[Table]") {

    SECTION("Move an object in edge to North") {
    }
    SECTION("Move an object in edge to East") {
    }
    SECTION("Move an object in edge to South") {
    }
    SECTION("Move an object in edge to West") {
    }
}

TEST_CASE("Table: Turn an object to the left", "[Table]") {

    SECTION("Turn an object facing North to the left") {
    }
    SECTION("Turn an object facing East to the left") {
    }
    SECTION("Turn an object facing South to the left") {
    }
    SECTION("Turn an object facing West to the left") {
    }
}

TEST_CASE("Table: Turn an object to the right", "[Table]") {

    SECTION("Turn an object facing North to the right") {
    }
    SECTION("Turn an object facing East to the right") {
    }
    SECTION("Turn an object facing South to the right") {
    }
    SECTION("Turn an object facing West to the right") {
    }
}
