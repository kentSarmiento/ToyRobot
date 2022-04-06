#ifndef ENTITY_TABLE_H_
#define ENTITY_TABLE_H_

#include <map>

#include "base_object.h"
#include "robot_object.h"

using namespace std;

namespace toyrobot {

class Table {

public:
    Table() {
        table_size_ = kDefinedTableSize;
    }

    ~Table();

    bool IsCoordinatesAvailable(const Coordinates& position);
    int PlaceObject(BaseObject *object);

    bool IsCoordinatesAvailable(int id, const Coordinates& position);
    int PlaceObject(int id, BaseObject *object);

    void MoveObject(int id);
    void TurnObjectLeft(int id);
    void TurnObjectRight(int id);
    string ReportObject(int id);

protected:
    map <int, BaseObject *> objects_;

private:
    static const int kDefinedTableSize = 5;
    int table_size_;

    BaseObject *GetObject(int id);

    bool IsCoordinatesValid(const Coordinates& position);

    bool IsCoordinatesFree(const Coordinates& position);
    bool IsCoordinatesFree(int id, const Coordinates& position);

    bool CanObjectMove(BaseObject* object);
};

} // namespace toyrobot

#endif // ENTITY_TABLE_H_