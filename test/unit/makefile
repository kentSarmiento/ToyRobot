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

VALUE = coordinates.o direction.o request_type.o
ENTITY = robot_object.o object_factory.o table.o
REQUEST = request_factory.o place_request.o
HANDLER = request_handler.o

TESTS = test_base_object.o test_robot_object.o test_object_factory.o test_table.o \
        test_place_request.o test_left_request.o test_right_request.o \
        test_move_request.o test_report_request.o test_request_factory.o \
        test_base_response.o test_place_response.o test_report_response.o \
        test_request_handler.o
TARGET = test_main.o
OUT = main

$(OUT): $(TARGET) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE) $(TESTS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TARGET) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE) $(TESTS)

coordinates.o: $(SRCDIR)/lib/value/coordinates.cc $(SRCDIR)/lib/value/coordinates.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/coordinates.cc

direction.o: $(SRCDIR)/lib/value/direction.cc $(SRCDIR)/lib/value/direction.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/direction.cc

request_type.o: $(SRCDIR)/lib/value/request_type.cc $(SRCDIR)/lib/value/request_type.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/request_type.cc

test_base_object.o: $(UNITTESTDIR)/lib/entity/test_base_object.cc $(UNITTESTDIR)/lib/entity/test_base_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_base_object.cc

robot_object.o: $(SRCDIR)/lib/entity/robot_object.cc $(SRCDIR)/lib/entity/robot_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/entity/robot_object.cc

object_factory.o: $(SRCDIR)/lib/entity/object_factory.cc $(SRCDIR)/lib/entity/object_factory.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/entity/object_factory.cc

test_robot_object.o: $(UNITTESTDIR)/lib/entity/test_robot_object.cc $(UNITTESTDIR)/lib/entity/test_robot_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_robot_object.cc

test_object_factory.o: $(UNITTESTDIR)/lib/entity/test_object_factory.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_object_factory.cc

table.o: $(SRCDIR)/lib/entity/table.cc $(SRCDIR)/lib/entity/table.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/entity/table.cc

test_table.o: $(UNITTESTDIR)/lib/entity/test_table.cc $(UNITTESTDIR)/lib/entity/test_table.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_table.cc

test_base_request.o: $(UNITTESTDIR)/lib/request/test_base_request.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_base_request.cc

request_factory.o: $(SRCDIR)/lib/request/request_factory.cc $(SRCDIR)/lib/request/request_factory.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/request/request_factory.cc

place_request.o: $(SRCDIR)/lib/request/place_request.cc $(SRCDIR)/lib/request/place_request.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/request/place_request.cc

test_place_request.o: $(UNITTESTDIR)/lib/request/test_place_request.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_place_request.cc

test_left_request.o: $(UNITTESTDIR)/lib/request/test_left_request.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_left_request.cc

test_right_request.o: $(UNITTESTDIR)/lib/request/test_right_request.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_right_request.cc

test_move_request.o: $(UNITTESTDIR)/lib/request/test_move_request.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_move_request.cc

test_report_request.o: $(UNITTESTDIR)/lib/request/test_report_request.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_report_request.cc

test_request_factory.o: $(UNITTESTDIR)/lib/request/test_request_factory.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_request_factory.cc

test_base_response.o: $(UNITTESTDIR)/lib/response/test_base_response.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/response/test_base_response.cc

test_place_response.o: $(UNITTESTDIR)/lib/response/test_place_response.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/response/test_place_response.cc

test_report_response.o: $(UNITTESTDIR)/lib/response/test_report_response.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/response/test_report_response.cc

request_handler.o: $(SRCDIR)/lib/handler/request_handler.cc $(SRCDIR)/lib/handler/request_handler.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/handler/request_handler.cc

test_request_handler.o: $(UNITTESTDIR)/lib/handler/test_request_handler.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/handler/test_request_handler.cc

test_main.o: $(UNITTESTDIR)/test_main.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/test_main.cc

all: $(OUT)

clean:
	rm -f $(OUT) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE) $(TESTS)

all_clean:
	rm -f $(OUT) *.o *.gc* *.info
	rm -rf $(HTML_OUTPUT)

test:
	./$(OUT)

coverage:
	gcov *.gcno
	lcov --capture --directory . --output-file $(COVERAGE_INFO)
	lcov --remove $(COVERAGE_INFO) '/usr/include/*' '*/test/*' -o $(COVERAGE_INFO)
	mkdir -p $(HTML_OUTPUT)
	genhtml $(COVERAGE_INFO) --output=$(HTML_OUTPUT)
