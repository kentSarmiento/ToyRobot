#ifndef ENTITY_TEST_BASE_OBJECT_H_
#define ENTITY_TEST_BASE_OBJECT_H_

#include "base_object.h"
#include "object_type.h"

using namespace toyrobot;

class TestBaseObject : public BaseObject {

public:
    TestBaseObject(): BaseObject() {}

    TestBaseObject(Coordinates position)
        : BaseObject(position) {}

    TestBaseObject(Coordinates position, ObjectType type)
        : BaseObject(position, type) {}

    TestBaseObject(const TestBaseObject &o)
        : BaseObject(o) {}

    int get_id();
    int get_x_position();
    int get_y_position();
    ObjectType get_type();
};

inline int TestBaseObject::get_id() {
    return id_;
}

inline int TestBaseObject::get_x_position() {
    return position_.x;
}

inline int TestBaseObject::get_y_position() {
    return position_.y;
}

inline ObjectType TestBaseObject::get_type() {
    return type_;
}

#endif // ENTITY_TEST_BASE_OBJECT_H_