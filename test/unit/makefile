CXX = g++
CXXFLAGS = -g -Wall -fprofile-arcs -ftest-coverage

SRCDIR = ../../src
TESTDIR = ../../test
UNITTESTDIR = $(TESTDIR)/unit

COVERAGE_INFO = $(UNITTESTDIR)/coverage.info
HTML_OUTPUT = $(UNITTESTDIR)/html

INCS = -I$(TESTDIR) \
       -I$(TESTDIR)/lib/entity \
       -I$(SRCDIR)/lib/entity \
       -I$(SRCDIR)/lib/value

ENTITY = test_base_object.o test_robot_object.o
TARGET = test_main.o
OUT = main

$(OUT): $(TARGET) $(ENTITY)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TARGET) $(ENTITY)

test_base_object.o: $(UNITTESTDIR)/lib/entity/test_base_object.cc $(UNITTESTDIR)/lib/entity/test_base_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_base_object.cc

test_robot_object.o: $(UNITTESTDIR)/lib/entity/test_robot_object.cc $(UNITTESTDIR)/lib/entity/test_robot_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_robot_object.cc

test_main.o: $(UNITTESTDIR)/test_main.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/test_main.cc

all: $(OUT)

clean:
	rm -f $(OUT) $(ENTITY)

all_clean:
	rm -f $(OUT) *.o *.gc* *.info
	rm -rf $(HTML_OUTPUT)

coverage:
	./$(OUT)
	gcov *.gcno
	lcov --capture --directory . --output-file $(COVERAGE_INFO)
	lcov --remove $(COVERAGE_INFO) '/usr/include/*' '*/test/*' -o $(COVERAGE_INFO)
	mkdir -p $(HTML_OUTPUT)
	genhtml $(COVERAGE_INFO) --output=$(HTML_OUTPUT)
