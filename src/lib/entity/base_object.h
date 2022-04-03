#ifndef ENTITY_BASE_OBJECT_H_
#define ENTITY_BASE_OBJECT_H_

#include "object_type.h"
#include "coordinates.h"

namespace toyrobot {

class BaseObject {

public:
    BaseObject() : position_(0, 0), type_(kObjectType) {
        id_ = 0;
    }

    BaseObject(Coordinates position)
        : position_(position),
          type_(kObjectType) {
        id_ = 0;
    }

    BaseObject(Coordinates position, ObjectType type)
        : position_(position),
          type_(type) {
        id_ = 0;
    }

    BaseObject(int id, Coordinates position, ObjectType type)
        : position_(position),
          type_(type) {
        id_ = id;
    }

    BaseObject(const BaseObject &o) {
        id_ = o.id_;
        position_ = o.position_;
        type_ = o.type_;
    }

protected:
    int id_;
    Coordinates position_;
    ObjectType type_;
};

} // namespace toyrobot

#endif // ENTITY_BASE_OBJECT_H_