CXX = g++
CXXFLAGS = -g -Wall -Werror -fprofile-arcs -ftest-coverage

SRCDIR = ../../src
TESTDIR = ../../test
UNITTESTDIR = $(TESTDIR)/unit

COVERAGE_INFO = $(UNITTESTDIR)/coverage.info
HTML_OUTPUT = $(UNITTESTDIR)/html

INCS = -I$(TESTDIR) \
       -I$(UNITTESTDIR)

TESTER = catch.hpp
TESTS = test_base_object.o test_robot_object.o test_object_factory.o test_table.o \
        test_place_request.o test_left_request.o test_right_request.o \
        test_move_request.o test_report_request.o test_request_factory.o \
        test_base_response.o test_place_response.o test_report_response.o \
        test_request_handler.o
APP = test_main.o

OUT = main
all: $(OUT)

include $(SRCDIR)/lib/modules.mk

$(OUT): $(TESTER) $(APP) $(LIBRARY) $(TESTS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(APP) $(LIBRARY) $(TESTS)

catch.hpp:
	test -f $(TESTDIR)/catch.hpp || wget -O $(TESTDIR)/catch.hpp https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp

test_base_object.o: $(UNITTESTDIR)/lib/entity/test_base_object.cc $(UNITTESTDIR)/lib/entity/test_base_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_base_object.cc

test_robot_object.o: $(UNITTESTDIR)/lib/entity/test_robot_object.cc $(UNITTESTDIR)/lib/entity/test_robot_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_robot_object.cc

test_object_factory.o: $(UNITTESTDIR)/lib/entity/test_object_factory.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_object_factory.cc

test_table.o: $(UNITTESTDIR)/lib/entity/test_table.cc $(UNITTESTDIR)/lib/entity/test_table.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_table.cc

test_base_request.o: $(UNITTESTDIR)/lib/request/test_base_request.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/request/test_base_request.cc

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

test_request_handler.o: $(UNITTESTDIR)/lib/handler/test_request_handler.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/handler/test_request_handler.cc

test_main.o: $(UNITTESTDIR)/test_main.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/test_main.cc

clean:
	rm -f $(OUT) $(APP) $(LIBRARY) $(TESTS)

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

leak_check:
	valgrind --log-file=valgrind.txt --leak-check=full ./$(OUT)
