#ifndef ENTITY_TEST_ROBOT_OBJECT_H_
#define ENTITY_TEST_ROBOT_OBJECT_H_

#include "robot_object.h"
#include "test_base_object.h"

using namespace toyrobot;

class TestRobotObject : public RobotObject {

public:
    TestRobotObject() : RobotObject() {}

    TestRobotObject(int id, Coordinates position, Direction facing)
        : RobotObject(id, position, facing) {}

    TestRobotObject(const TestRobotObject &r)
        : RobotObject(r) {}

    int get_id();
    int get_x_position();
    int get_y_position();
    ObjectType get_type();
    Direction get_facing();
};

inline int TestRobotObject::get_id() {
    return id_;
}

inline int TestRobotObject::get_x_position() {
    return position_.x;
}

inline int TestRobotObject::get_y_position() {
    return position_.y;
}

inline ObjectType TestRobotObject::get_type() {
    return type_;
}

inline Direction TestRobotObject::get_facing() {
    return facing_;
}

#endif // ENTITY_TEST_ROBOT_OBJECT_H_