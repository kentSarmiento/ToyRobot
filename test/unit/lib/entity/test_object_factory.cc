#include "catch.hpp"
#include "object_factory.h"
#include "object_type.h"

using namespace toyrobot;

TEST_CASE("ObjectFactory: Create Objects", "[ObjectFactory]") {

    SECTION("Create Robot Object") {
        BaseObject *object =  ObjectFactory::CreateObject(ObjectType::kRobotType, Coordinates(0,0), Direction());

        REQUIRE(object);
        delete object;
    }
}
