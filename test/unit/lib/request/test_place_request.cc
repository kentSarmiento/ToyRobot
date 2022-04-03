#include "catch.hpp"
#include "place_request.h"
#include "coordinates.h"
#include "directions.h"
#include "request_type.h"

using namespace toyrobot;

TEST_CASE("PlaceRequest: Valid requests", "[PlaceRequest]") {

    SECTION("Request to set an object at position (0,0) facing NORTH") {
        PlaceRequest request(0, "0,0,NORTH");

        REQUIRE(request.request_name() == RequestType::kPlaceRequest);
        REQUIRE(request.object_id() == 0);
        REQUIRE(request.is_valid());
        REQUIRE(request.position() == Coordinates(0,0));
        REQUIRE(request.direction() == kFacingNorth);
    }
    SECTION("Request to set an object at position (0,4) facing EAST") {
        PlaceRequest request(0, "0,4,EAST");

        REQUIRE(request.request_name() == RequestType::kPlaceRequest);
        REQUIRE(request.object_id() == 0);
        REQUIRE(request.is_valid());
        REQUIRE(request.position() == Coordinates(0,4));
        REQUIRE(request.direction() == kFacingEast);
    }
    SECTION("Request to set an object at position (4,4) facing SOUTH") {
        PlaceRequest request(0, "4,4,SOUTH");

        REQUIRE(request.request_name() == RequestType::kPlaceRequest);
        REQUIRE(request.object_id() == 0);
        REQUIRE(request.is_valid());
        REQUIRE(request.position() == Coordinates(4,4));
        REQUIRE(request.direction() == kFacingSouth);
    }
    SECTION("Request to set an object at position (4,0) facing WEST") {
        PlaceRequest request(0, "4,0,WEST");

        REQUIRE(request.request_name() == RequestType::kPlaceRequest);
        REQUIRE(request.object_id() == 0);
        REQUIRE(request.is_valid());
        REQUIRE(request.position() == Coordinates(4,0));
        REQUIRE(request.direction() == kFacingWest);
    }
}

TEST_CASE("PlaceRequest: Invalid requests", "[PlaceRequest]") {

    SECTION("Request to set an object at position (0,0)") {
        PlaceRequest request(0, "0,0");

        REQUIRE(!request.is_valid());
    }
    SECTION("Request to set an object at invalid position 0") {
        PlaceRequest request(0, "0");

        REQUIRE(!request.is_valid());
    }
    SECTION("Request to set an object at invalid position 0,") {
        PlaceRequest request(0, "0,");

        REQUIRE(!request.is_valid());
    }
    SECTION("Request to set an object at invalid position 0,0,") {
        PlaceRequest request(0, "0,0,");

        REQUIRE(!request.is_valid());
    }
    SECTION("Request to set an object at invalid position 0,0,1") {
        PlaceRequest request(0, "0,0,1");

        REQUIRE(!request.is_valid());
    }
}