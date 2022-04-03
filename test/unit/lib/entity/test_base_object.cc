#include "catch.hpp"
#include "test_base_object.h"

TEST_CASE("BaseObject: Default constructor", "[BaseObject]") {
    TestBaseObject test_object;

    REQUIRE(test_object.get_id() == 0);
    REQUIRE(test_object.get_x_position() == 0);
    REQUIRE(test_object.get_y_position() == 0);
    REQUIRE(test_object.get_type() == kObjectType);
}

TEST_CASE("BaseObject: Constructor with position parameter", "[BaseObject]") {
    TestBaseObject test_object(Coordinates(1,1));

    REQUIRE(test_object.get_id() == 0);
    REQUIRE(test_object.get_x_position() == 1);
    REQUIRE(test_object.get_y_position() == 1);
    REQUIRE(test_object.get_type() == kObjectType);
}

TEST_CASE("BaseObject: Constructor with position and type parameter", "[BaseObject]") {
    TestBaseObject test_object(Coordinates(1,1), kRobotType);

    REQUIRE(test_object.get_id() == 0);
    REQUIRE(test_object.get_x_position() == 1);
    REQUIRE(test_object.get_y_position() == 1);
    REQUIRE(test_object.get_type() == kRobotType);
}

TEST_CASE("BaseObject: Complete constructor", "[BaseObject]") {
    TestBaseObject test_object(1, Coordinates(1,1), kRobotType);

    REQUIRE(test_object.get_id() == 1);
    REQUIRE(test_object.get_x_position() == 1);
    REQUIRE(test_object.get_y_position() == 1);
    REQUIRE(test_object.get_type() == kRobotType);
}

TEST_CASE("BaseObject: Copy constructor", "[BaseObject]") {
    TestBaseObject test_object(1, Coordinates(1,1), kRobotType);
    TestBaseObject new_object(test_object);

    REQUIRE(new_object.get_id() == 1);
    REQUIRE(new_object.get_x_position() == 1);
    REQUIRE(new_object.get_y_position() == 1);
    REQUIRE(new_object.get_type() == kRobotType);
}
