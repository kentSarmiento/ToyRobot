#ifndef ENTITY_OBJECT_FACTORY_H_
#define ENTITY_OBJECT_FACTORY_H_

#include "base_object.h"
#include "object_type.h"
#include "coordinates.h"
#include "direction.h"

namespace toyrobot {

class ObjectFactory {

public:
    static BaseObject* CreateObject(ObjectType object_type, Coordinates position, Direction facing);
};

} // namespace toyrobot

#endif // ENTITY_OBJECT_FACTORY_H_