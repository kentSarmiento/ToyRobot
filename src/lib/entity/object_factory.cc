#include "object_factory.h"
#include "robot_object.h"

namespace toyrobot {

BaseObject* ObjectFactory::CreateObject(const ObjectType& object_type,
                                        const Coordinates& position,
                                        const Direction& facing)
{
    BaseObject* object = nullptr;
    if (object_type == ObjectType::kRobotType) {
        object = new RobotObject(position, facing);
    }
    return object;
}

} // namespace toyrobot