# Toy Robot Code Challenge [![CI](https://github.com/kentSarmiento/ToyRobot/actions/workflows/ci.yml/badge.svg)](https://github.com/kentSarmiento/ToyRobot/actions/workflows/ci.yml)

This project contains a Solution to a Toy Robot Coding Challenge.

## Challenge

The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

Create a **console application** that can read commands of the following form:  
* PLACE X,Y,F  
Puts the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST, or WEST.
* MOVE  
Moves the toy robot one unit forward in the direction it is currently facing.
* LEFT  
Rotates the toy robot 90 degrees to the left.
* RIGHT  
Rotates the toy robot 90 degrees to the right.
* REPORT  
Announces the X,Y, and F of the robot.

The origin (0,0) can be considered to be the SOUTH WEST most corner. It is required that the first command to the robot is a PLACE command. After that, any sequence of commands may be issued, in any order, including another PLACE command. The application should discard all commands in the sequence until a valid PLACE command has been executed.

A robot that is not on the table can choose to ignore any commands. Input can from a file, or from standard input. The robot must not fall off the table during movement. This also includes the initial placement of the toy robot. Any move that would cause the robot to fall must be ignored.

The application should handle error states appropriately and be robust to user input.

## What's contained in this project

* [Source Implementation](src/)  
Source Implementation contains the following:
  * [Library](src/README.md#library)  
  Implements a library to be used for the challenge.
  * [Application](src/README.md#application)  
  Uses the Library to implement a Single Toy Robot moving on the table top.

* [Test Implementation](test/)  
Test Implementation contains two levels of tests:
  * [Integration Test](test/README.md#integration-test)  
  * [Unit Test](test/README.md#unit-test)  

## Project Setup and Usage

The project is developed in a Debian 10 environment using `gcc version 10.2.1`.

### Building the project

The project uses makefile to build the implementation.  
In the `src` directory, the application can be built from the command line using `make` command.  
```
make
```

An executable named `main` is created after the compilation is successful.  
For more information and other features, refer to [src documentation](src/README.md).

### Running the project

After the project is built, the Application can be executed from the command line.  

Input commands can be provided from file or standard input.  
* Using standard input
   ```
   ./main
   ```
* Using a file as input
   ```
   ./main < {location of input file}
   ```

#### File inputs for the Application

Sample input files are available below:
* [input1.txt](test/input/input1.txt)  
This input file contains sample Input and Output from the Specifications
* [input2.txt](test/input/input2.txt)  
This input file contains multiple invalid commands to test that the Application is robust to User input.
* [input3.txt](test/input/input3.txt)  
This input file makes a toy robot traverse the whole table while trying not to fall.

### Testing the project

#### Prerequisites

Catch2v2 is the Testing Framework used for the tests.  
To build the tests, `wget` should be available in the environment to download `catch.hpp` header file.  
`catch.hpp` can also be manually downloaded and saved in the `test` directory.

#### Integration Test

Integration tests are implemented to verify the Specifications implemented in the project.  
For more information about the Integration Test implementation, refer to [test documentation](test/README.md#integration-test).

In the `test/integration` directory, the tests can be built from the commmand line using `make` command.
```
make
```

Then, the tests can be executed using `make test` command.
```
make test
```

#### Unit Test

Unit tests are implemented to verify implementation of each Unit in the project.  
For more information about the Unit Test implementation, refer to [test documentation](test/README.md#unit-test).

In the `test/unit` directory, the tests can be built from the commmand line using `make` command.
```
make
```

Then, the tests can be executed using `make test` command.
```
make test
```
### Project CI

The project uses Github Actions to automate build and tests
* [ci.yml](.github/workflows/ci.yml) file used for the following workflow
  * Build
  * Unit Test (archives coverage results)
  * Integration Test
