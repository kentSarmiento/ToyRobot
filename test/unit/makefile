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

VALUE = directions.o
ENTITY = test_base_object.o robot_object.o test_robot_object.o table.o test_table.o
TARGET = test_main.o
OUT = main

$(OUT): $(TARGET) $(ENTITY) $(VALUE)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TARGET) $(ENTITY) $(VALUE)

directions.o: $(SRCDIR)/lib/value/directions.cc $(SRCDIR)/lib/value/directions.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/directions.cc

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

test_main.o: $(UNITTESTDIR)/test_main.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/test_main.cc

all: $(OUT)

clean:
	rm -f $(OUT) $(ENTITY)

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
