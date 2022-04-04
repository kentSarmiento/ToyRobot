#include "catch.hpp"
#include "test_base_object.h"

TEST_CASE("BaseObject: Default constructor", "[BaseObject]") {
    TestBaseObject test_object;

    REQUIRE(test_object.id() == 0);
    REQUIRE(test_object.x_position() == 0);
    REQUIRE(test_object.y_position() == 0);
    REQUIRE(test_object.type() == kObjectType);
}

TEST_CASE("BaseObject: Constructor with position parameter", "[BaseObject]") {
    TestBaseObject test_object(Coordinates(1,1));

    REQUIRE(test_object.id() == 0);
    REQUIRE(test_object.x_position() == 1);
    REQUIRE(test_object.y_position() == 1);
    REQUIRE(test_object.type() == kObjectType);
}

TEST_CASE("BaseObject: Constructor with position and type parameter", "[BaseObject]") {
    TestBaseObject test_object(Coordinates(1,1), kRobotType);

    REQUIRE(test_object.id() == 0);
    REQUIRE(test_object.x_position() == 1);
    REQUIRE(test_object.y_position() == 1);
    REQUIRE(test_object.type() == kRobotType);
}

TEST_CASE("BaseObject: Copy constructor", "[BaseObject]") {
    TestBaseObject test_object(Coordinates(1,1), kRobotType);
    TestBaseObject new_object(test_object);

    REQUIRE(new_object.id() == 0);
    REQUIRE(new_object.x_position() == 1);
    REQUIRE(new_object.y_position() == 1);
    REQUIRE(new_object.type() == kRobotType);
}