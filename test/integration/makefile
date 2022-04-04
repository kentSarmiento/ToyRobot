CXX = g++
CXXFLAGS = -g -Wall

SRCDIR = ../../src
TESTDIR = ../../test
INTEGRATIONTESTDIR = $(TESTDIR)/integration

INCS = -I$(TESTDIR) \
       -I$(SRCDIR)/lib/entity \
       -I$(SRCDIR)/lib/request \
       -I$(SRCDIR)/lib/handler \
       -I$(SRCDIR)/lib/response \
       -I$(SRCDIR)/lib/value

VALUE = directions.o request_type.o
ENTITY = robot_object.o table.o
REQUEST = request_factory.o
HANDLER = request_handler.o
TESTS = test_single.o
TARGET = test_main.o
OUT = main

$(OUT): $(TARGET) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE) $(TESTS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TARGET) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE) $(TESTS)

directions.o: $(SRCDIR)/lib/value/directions.cc $(SRCDIR)/lib/value/directions.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/directions.cc

request_type.o: $(SRCDIR)/lib/value/request_type.cc $(SRCDIR)/lib/value/request_type.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/request_type.cc

robot_object.o: $(SRCDIR)/lib/entity/robot_object.cc $(SRCDIR)/lib/entity/robot_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/entity/robot_object.cc

table.o: $(SRCDIR)/lib/entity/table.cc $(SRCDIR)/lib/entity/table.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/entity/table.cc

request_factory.o: $(SRCDIR)/lib/request/request_factory.cc $(SRCDIR)/lib/request/request_factory.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/request/request_factory.cc

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
