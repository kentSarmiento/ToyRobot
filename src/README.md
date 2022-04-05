# Project Source Implementation

## Library

### Entity

The [`entity`](lib/entity/) module contains the `Table` and `Object` classes.

The classes has an Aggregate relationship (Table is the aggregate root, which could contain one or more Object).  
* [table](lib/entity/table.h)  
  Aggregate root. Can contain one or more Objects.
* objects
  * [robot](lib/entity/robot_object.h)  
  An object which can be added into the table.

### Handler

The [`handler`](lib/handler/) module receives requests from the application.  
An Application needs to have a [RequestHandler](lib/handler/request_handler.h) object to use the Library.

The following are the main methods an Application is expected to use:
* `RequestHandler::CreateRequest()`  
Method to create requests/commands.
* `RequestHandler::HandleCommmand()`  
Method to execute the requests/commands.

Sample application:
```
  RequestHandler handler;

  BaseRequest *request = handler.CreateRequest("PLACE", "0,0,NORTH");
  BaseResponse *response = handler.HandleCommand(request);
```

### Request

The [`request`](lib/request/) module contains the Request objects which can be sent by an application into the `handler` module.

### Response

The [`response`](lib/response/) module contains the Response objects which can be sent to the application from the `handler` module.

### Value

The [`value`](lib/value/) module contains the Value objects used within the library.

## Application

### Single Robot

The [single robot](apps/single.cc) is a sample application which solves the [coding challenge](../README.md#challenge).

A single robot can be placed and controlled within the Table.

#### How to Run the Application

In the `src` directory, the application can be built from the command line using `make` command.
```
make
```

An executable named `main` is created after the compilation is successful.

When the Application is executed, commmands can be received from the command line or from an input file.
* Running the application and sending commands from standard input
  ```
  ./main
  ```
* Running the application and sending commands from input file
  ```
  ./main < {location of input file}
  ```