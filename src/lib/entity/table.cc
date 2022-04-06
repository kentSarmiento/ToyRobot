#include "table.h"

using namespace std;

namespace toyrobot {

Table::~Table() {
    for (auto it = objects_.begin(); it != objects_.end(); it++) {
        delete it->second;
    }
    objects_.clear();
}

bool Table::IsCoordinatesAvailable(const Coordinates& position) {
    return IsCoordinatesValid(position) && IsCoordinatesFree(position);
}

int Table::PlaceObject(BaseObject *object) {
    int id = -1;
    if (object) {
        id = objects_.size();
        objects_[id] = object;
    }

    return id;
}

bool Table::IsCoordinatesAvailable(int id, const Coordinates& position) {
    return IsCoordinatesValid(position) && IsCoordinatesFree(id, position);
}

int Table::PlaceObject(int id, BaseObject *object) {
    if (!object) {
        id = -1;
    } else {
        if (objects_.find(id) != objects_.end()) {
            delete objects_[id];
        } else {
            id = objects_.size();
        }

        objects_[id] = object;
    }

    return id;
}

void Table::MoveObject(int id) {
    BaseObject *object = GetObject(id);
    if (object && CanObjectMove(object)) {
        object->Move();
    }
}

void Table::TurnObjectLeft(int id) {
    BaseObject *object = GetObject(id);
    if (object) {
        object->TurnLeft();
    }
}

void Table::TurnObjectRight(int id) {
    BaseObject *object = GetObject(id);
    if (object) {
        object->TurnRight();
    }
}

string Table::ReportObject(int id) {
    string output;

    BaseObject *object = GetObject(id);
    if (object) {
        output = object->Report();
    }

    return output;
}

BaseObject *Table::GetObject(int id) {
    auto it = objects_.find(id);
    if (it != objects_.end()) {
        return it->second;
    }

    return nullptr;
}

bool Table::IsCoordinatesValid(const Coordinates& position) {
    if (position.x < 0 || position.x >= table_size_ ||
        position.y < 0 || position.y >= table_size_) {
        return false;
    }
    return true;
}

bool Table::IsCoordinatesFree(const Coordinates& position) {
    for (auto it = objects_.begin(); it != objects_.end(); it++)
        if (it->second->position() == position)
            return false;

    return true;
}

bool Table::IsCoordinatesFree(int id, const Coordinates& position) {
    for (auto it = objects_.begin(); it != objects_.end(); it++) {
        if (it->second->position() == position && it->second == objects_[id])
            return true;
        if (it->second->position() == position)
            return false;
    }

    return true;
}

bool Table::CanObjectMove(BaseObject *object) {
    return (object && IsCoordinatesAvailable(object->GetMovePosition()));
}

} // namespace toyrobot