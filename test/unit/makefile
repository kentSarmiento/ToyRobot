CXX = g++
CXXFLAGS = -g -Wall -fprofile-arcs -ftest-coverage

SRCDIR = ../../src
TESTDIR = ../../test
UNITTESTDIR = $(TESTDIR)/unit

COVERAGE_INFO = $(UNITTESTDIR)/coverage.info
HTML_OUTPUT = $(UNITTESTDIR)/html

INCS = -I$(TESTDIR) \
       -I$(TESTDIR)/lib/entity \
       -I$(TESTDIR)/lib/request \
       -I$(TESTDIR)/lib/handler \
       -I$(TESTDIR)/lib/response \
       -I$(SRCDIR)/lib/entity \
       -I$(SRCDIR)/lib/request \
       -I$(SRCDIR)/lib/handler \
       -I$(SRCDIR)/lib/response \
       -I$(SRCDIR)/lib/value

VALUE = directions.o request_type.o
ENTITY = test_base_object.o robot_object.o test_robot_object.o table.o test_table.o
REQUEST = test_base_request.o test_place_request.o request_factory.o test_request_factory.o
HANDLER = test_request_handler.o
RESPONSE =
TARGET = test_main.o
OUT = main

$(OUT): $(TARGET) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TARGET) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE)

directions.o: $(SRCDIR)/lib/value/directions.cc $(SRCDIR)/lib/value/directions.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/directions.cc

request_type.o: $(SRCDIR)/lib/value/request_type.cc $(SRCDIR)/lib/value/request_type.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/request_type.cc

test_base_object.o: $(UNITTESTDIR)/lib/entity/test_base_object.cc $(UNITTESTDIR)/lib/entity/test_base_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_base_object.cc

robot_object.o: $(SRCDIR)/lib/entity/robot_object.cc $(SRCDIR)/lib/entity/robot_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/entity/robot_object.cc

test_robot_object.o: $(UNITTESTDIR)/lib/entity/test_robot_object.cc $(UNITTESTDIR)/lib/entity/test_robot_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_robot_object.cc

table.o: $(SRCDIR)/lib/entity/table.cc $(SRCDIR)/lib/entity/table.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/entity/table.cc

test_table.o: $(UNITTESTDIR)/lib/entity/test_table.cc $(UNITTESTDIR)/lib/entity/test_table.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_table.cc

test_base_request.o: $(UNITTESTDIR)/lib/request/test_base_request.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_base_request.cc

test_place_request.o: $(UNITTESTDIR)/lib/request/test_place_request.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_place_request.cc

request_factory.o: $(SRCDIR)/lib/request/request_factory.cc $(SRCDIR)/lib/request/request_factory.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/request/request_factory.cc

test_request_factory.o: $(UNITTESTDIR)/lib/request/test_request_factory.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_request_factory.cc

test_request_handler.o: $(UNITTESTDIR)/lib/handler/test_request_handler.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/handler/test_request_handler.cc

test_main.o: $(UNITTESTDIR)/test_main.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/test_main.cc

all: $(OUT)

clean:
	rm -f $(OUT) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE)

all_clean:
	rm -f $(OUT) *.o *.gc* *.info
	rm -rf $(HTML_OUTPUT)

test:
	./$(OUT)

coverage:
	./$(OUT)
	gcov *.gcno
	lcov --capture --directory . --output-file $(COVERAGE_INFO)
	lcov --remove $(COVERAGE_INFO) '/usr/include/*' '*/test/*' -o $(COVERAGE_INFO)
	mkdir -p $(HTML_OUTPUT)
	genhtml $(COVERAGE_INFO) --output=$(HTML_OUTPUT)
