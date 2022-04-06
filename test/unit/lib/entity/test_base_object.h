#ifndef ENTITY_TEST_BASE_OBJECT_H_
#define ENTITY_TEST_BASE_OBJECT_H_

#include "base_object.h"
#include "object_type.h"

using namespace toyrobot;

class TestBaseObject : public BaseObject {

public:
    TestBaseObject(): BaseObject() {}

    explicit TestBaseObject(Coordinates position)
        : BaseObject(position) {}

    TestBaseObject(Coordinates position, ObjectType type)
        : BaseObject(position, type) {}

    TestBaseObject(const TestBaseObject &o)
        : BaseObject(o) {}

    Coordinates GetMovePosition() override { return Coordinates(); }
    void Move() override {}

    void TurnLeft() override {}
    void TurnRight() override {}

    string Report() override { return {}; }

    int id() { return id_; }
    int x_position() { return position().x; }
    int y_position() { return position().y; }
    ObjectType type() { return type_; }
};

#endif // ENTITY_TEST_BASE_OBJECT_H_