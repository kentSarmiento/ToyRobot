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

Coverage can be measured using `make coverage` command (`lcov` is needed).
```
make coverage
```

Memory Leak can be checked using `make leak_check` command (`valgrind` is needed).
```
make leak_check
```

### Current Unit Test Statistics

* Number of test cases: 37
* Number of assertions: 566
* Coverage:
  * Lines: 100% (308 of 308 lines)
  * Functions: 97.8% (87 of 89 lines)