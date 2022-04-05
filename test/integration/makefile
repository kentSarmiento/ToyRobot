CXX = g++
CXXFLAGS = -g -Wall

SRCDIR = ../../src
TESTDIR = ../../test
INTEGRATIONTESTDIR = $(TESTDIR)/integration

INCS = -I$(TESTDIR) \
       -I$(INTEGRATIONTESTDIR)

TESTER = catch.hpp
TESTS = test_single.o
APP = test_main.o

OUT = main
all: $(OUT)

include $(SRCDIR)/lib/modules.mk

$(OUT): $(TESTER) $(APP) $(LIBRARY) $(TESTS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(APP) $(LIBRARY) $(TESTS)

catch.hpp:
	test -f $(TESTDIR)/catch.hpp || wget -O $(TESTDIR)/catch.hpp https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp

test_single.o: $(INTEGRATIONTESTDIR)/test_single.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(INTEGRATIONTESTDIR)/test_single.cc

test_main.o: $(INTEGRATIONTESTDIR)/test_main.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(INTEGRATIONTESTDIR)/test_main.cc

clean:
	rm -f $(OUT) $(APP) $(LIBRARY) $(TESTS)

all_clean:
	rm -f $(OUT) *.o

test:
	./$(OUT)

leak_check:
	valgrind --log-file=valgrind.txt --leak-check=full ./$(OUT)