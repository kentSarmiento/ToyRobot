#ifndef ENTITY_BASE_OBJECT_H_
#define ENTITY_BASE_OBJECT_H_

#include <string>

#include "object_type.h"
#include "coordinates.h"

using namespace std;

namespace toyrobot {

class BaseObject {

public:
    BaseObject() : position_(0, 0), type_(kObjectType) {
        id_ = 0;
    }

    BaseObject(const Coordinates& position)
        : position_(position),
          type_(kObjectType) {
        id_ = 0;
    }

    BaseObject(const Coordinates& position, const ObjectType& type)
        : position_(position),
          type_(type) {
        id_ = 0;
    }

    BaseObject(const BaseObject &o) {
        id_ = o.id_;
        position_ = o.position_;
        type_ = o.type_;
    }

    virtual ~BaseObject() = default;

    virtual Coordinates GetMovePosition() = 0;
    virtual void Move() = 0;

    virtual void TurnLeft() = 0;
    virtual void TurnRight() = 0;

    virtual string Report() = 0;

    Coordinates position() { return position_; }

protected:
    int id_;
    Coordinates position_;
    ObjectType type_;
};

} // namespace toyrobot

#endif // ENTITY_BASE_OBJECT_H_