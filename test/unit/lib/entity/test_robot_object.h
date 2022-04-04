#ifndef ENTITY_TEST_ROBOT_OBJECT_H_
#define ENTITY_TEST_ROBOT_OBJECT_H_

#include "robot_object.h"

using namespace toyrobot;

class TestRobotObject : public RobotObject {

public:
    TestRobotObject() : RobotObject() {}

    TestRobotObject(Coordinates position, Direction facing)
        : RobotObject(position, facing) {}

    TestRobotObject(const TestRobotObject &r)
        : RobotObject(r) {}

    int id() { return id_; }
    int x_position() { return position().x; }
    int y_position() { return position().y; }
    ObjectType type() { return type_; }
    Direction facing() { return facing_; }
};

#endif // ENTITY_TEST_ROBOT_OBJECT_H_