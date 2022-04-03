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

    BaseObject(const BaseObject &o) {
        id_ = o.id_;
        position_ = o.position_;
        type_ = o.type_;
    }

    virtual ~BaseObject() = default;

    virtual Coordinates GetMovePosition() { return position_; }
    virtual void Move() {}

    virtual void TurnLeft() {}
    virtual void TurnRight() {}

    virtual string Report() { return {}; }

    bool ComparePosition(Coordinates position);

protected:
    int id_;
    Coordinates position_;
    ObjectType type_;
};

inline bool BaseObject::ComparePosition(Coordinates position) {
    return (position_.x == position.x && position_.y == position.y);
}

} // namespace toyrobot

#endif // ENTITY_BASE_OBJECT_H_