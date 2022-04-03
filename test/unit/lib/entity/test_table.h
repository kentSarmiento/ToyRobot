#ifndef ENTITY_TEST_TABLE_H_
#define ENTITY_TEST_TABLE_H_

#include "table.h"

using namespace toyrobot;

class TestTable : public Table {

public:
    TestTable() : Table() {}

    int get_object_count();
};

inline int TestTable::get_object_count() {
    return objects_.size();
}

#endif // ENTITY_TEST_TABLE_H_