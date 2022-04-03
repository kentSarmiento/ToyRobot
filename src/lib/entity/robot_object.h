#ifndef ENTITY_ROBOT_OBJECT_H_
#define ENTITY_ROBOT_OBJECT_H_

#include "base_object.h"
#include "directions.h"

namespace toyrobot {

class RobotObject : public BaseObject {

public:
    RobotObject() : BaseObject() {
        type_ = kRobotType;
        facing_ = kFacingNorth;
    }

    RobotObject(int id, Coordinates position, Direction facing)
        : BaseObject(id, position, kRobotType) {
        facing_ = facing;
    }

    RobotObject(const RobotObject &r) : BaseObject(r) {
        facing_ = r.facing_;
    }

    void Move();
    void TurnLeft();
    void TurnRight();
    string Report();

protected:
    Direction facing_;
};

inline void RobotObject::TurnLeft() {
    Directions::TurnLeft(facing_);
}

inline void RobotObject::TurnRight() {
    Directions::TurnRight(facing_);
}

} // namespace toyrobot

#endif // ENTITY_ROBOT_OBJECT_H_