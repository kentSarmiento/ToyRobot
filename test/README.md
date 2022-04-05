# Project Test Implementation

## Integration Test

Catch2v2 is the Testing Framework used for the tests.  
For Integration Testing, BDD-style testing is used.

`SCENARIO`, `GIVEN`, `WHEN`, and `THEN` macros are used to mark each test and serve as documentation.

Sample test for Single Robot Application:
```
SCENARIO("Moving robot", "[move]") {

    GIVEN("A table with a Robot placed at (0,0) facing NORTH") {

        WHEN("Robot is moved") {

            THEN("Robot is now located at (0,1) facing NORTH") {

            }
        }
    }
}
```

### How to Test

In the `test/integration` directory, the tests can be built from the command line using `make` command.
```
make
```

Then, the tests can be executed using `make test` command.
```
make test
```


## Unit Test

Catch2v2 is the Testing Framework used for the tests.  
For Unit Testing, TDD-style testing is used.

`TEST_CASE` macro marks each test case.  
`SECTION` macro marks each sub-test which shares a common Setup/Teardown with other sections within a test case.  
`REQUIRE` macro is used for the test assertions.  
`GENERATE` macro is used for parameterized test cases.

### How to Test

In the `test/unit` directory, the tests can be built from the commmand line using `make` command.
```
make
```

Then, the tests can be executed using `make test` command.
```
make test
```

In addition, coverage can be measured using `make coverage` command (`lcov` is used).
```
make coverage
```

### Current Unit Test Statistics

* Number of test cases: 35
* Number of assertions: 533
* Coverage:
  * Lines: 100% (287 of 287 lines)
  * Functions: 97.5% (79 of 81 lines)