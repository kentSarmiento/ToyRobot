#include "catch.hpp"


SCENARIO("Placing robot", "[adding]") {

    GIVEN("A table with a pre-defined size (5x5)") {

        WHEN("A Robot is placed at (0,0) facing NORTH") {

            THEN("A Robot is added to the Table") {

            }
        }
    }

    GIVEN("A table with a pre-defined size (5x5)") {

        WHEN("A Robot is placed at (5,5) facing NORTH") {

            THEN("A Robot is not added to the Table") {

            }
        }
    }
}

SCENARIO("Reporting robot state", "[report]") {

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {

        WHEN("A Robot is made to report its State") {

            THEN("A Robot is able to report its location at (0,0) and direction facing NORTH") {

            }
        }
    }
}

SCENARIO("Transferring robot", "[transfer]") {

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {

        WHEN("A Robot is place at (1,1) facing SOUTH") {

            THEN("Robot is now located at (1,1) facing SOUTH") {

            }
        }
    }

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {

        WHEN("A Robot is place at (5,5) facing SOUTH") {

            THEN("Robot is still located at (0,0) facing NORTH") {

            }
        }
    }
}

SCENARIO("Turning robot", "[turn]") {

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {

        WHEN("Robot is turned left") {

            THEN("Robot is now located at (0,0) facing WEST") {

            }
        }
    }

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {

        WHEN("Robot is turned right") {

            THEN("Robot is now located at (0,0) facing EAST") {

            }
        }
    }
}

SCENARIO("Moving robot", "[move]") {

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {

        WHEN("Robot is moved") {

            THEN("Robot is now located at (0,1) facing NORTH") {

            }
        }
    }

    GIVEN("A table with a Robot placed at (0,0) facing EAST") {

        WHEN("Robot is moved") {

            THEN("Robot is now located at (1,0) facing EAST") {

            }
        }
    }

    GIVEN("A table with a Robot placed at (0,0) facing SOUTH") {

        WHEN("Robot is moved") {

            THEN("Robot is still located at (0,0) facing SOUTH") {

            }
        }
    }

    GIVEN("A table with a Robot placed at (0,0) facing WEST") {

        WHEN("Robot is moved") {

            THEN("Robot is still located at (0,0) facing WEST") {

            }
        }
    }
}