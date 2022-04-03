#include "catch.hpp"
#include "test_table.h"

TEST_CASE("Table: Default constructor", "[Table]") {
    TestTable table;

    REQUIRE(table.get_object_count() == 0);
}
