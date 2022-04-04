CXX = g++
CXXFLAGS = -g -Wall

SRCDIR = ../../src
TESTDIR = ../../test
INTEGRATIONTESTDIR = $(TESTDIR)/integration

INCS = -I$(TESTDIR) \
       -I$(INTEGRATIONTESTDIR) \
       -I$(SRCDIR)/lib/entity \
       -I$(SRCDIR)/lib/request \
       -I$(SRCDIR)/lib/handler \
       -I$(SRCDIR)/lib/response \
       -I$(SRCDIR)/lib/value

VALUE = coordinates.o direction.o request_type.o
ENTITY = robot_object.o object_factory.o table.o
REQUEST = request_factory.o place_request.o
HANDLER = request_handler.o

TESTER = catch.hpp
TESTS = test_single.o
TARGET = test_main.o
OUT = main

$(OUT): $(TESTER) $(TARGET) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE) $(TESTS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TARGET) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE) $(TESTS)

catch.hpp:
	test -f $(TESTDIR)/catch.hpp || wget -O $(TESTDIR)/catch.hpp https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp

coordinates.o: $(SRCDIR)/lib/value/coordinates.cc $(SRCDIR)/lib/value/coordinates.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/coordinates.cc

direction.o: $(SRCDIR)/lib/value/direction.cc $(SRCDIR)/lib/value/direction.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/direction.cc

request_type.o: $(SRCDIR)/lib/value/request_type.cc $(SRCDIR)/lib/value/request_type.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/request_type.cc

robot_object.o: $(SRCDIR)/lib/entity/robot_object.cc $(SRCDIR)/lib/entity/robot_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/entity/robot_object.cc

object_factory.o: $(SRCDIR)/lib/entity/object_factory.cc $(SRCDIR)/lib/entity/object_factory.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/entity/object_factory.cc

table.o: $(SRCDIR)/lib/entity/table.cc $(SRCDIR)/lib/entity/table.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/entity/table.cc

request_factory.o: $(SRCDIR)/lib/request/request_factory.cc $(SRCDIR)/lib/request/request_factory.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/request/request_factory.cc

place_request.o: $(SRCDIR)/lib/request/place_request.cc $(SRCDIR)/lib/request/place_request.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/request/place_request.cc

request_handler.o: $(SRCDIR)/lib/handler/request_handler.cc $(SRCDIR)/lib/handler/request_handler.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/handler/request_handler.cc

test_single.o: $(INTEGRATIONTESTDIR)/test_single.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(INTEGRATIONTESTDIR)/test_single.cc

test_main.o: $(INTEGRATIONTESTDIR)/test_main.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(INTEGRATIONTESTDIR)/test_main.cc

all: $(OUT)

clean:
	rm -f $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE) $(TESTS)

all_clean:
	rm -f $(OUT) *.o

test:
	./$(OUT)
