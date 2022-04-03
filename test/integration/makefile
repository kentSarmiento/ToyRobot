CXX = g++
CXXFLAGS = -g -Wall

SRCDIR = ../../src
TESTDIR = ../../test
INTEGRATIONTESTDIR = $(TESTDIR)/integration

INCS = -I$(TESTDIR)

TESTS = test_sample.o test_specs.o
TARGET = test_main.o
OUT = main

$(OUT): $(TARGET) $(TESTS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TARGET) $(TESTS)

test_sample.o: $(INTEGRATIONTESTDIR)/test_sample.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(INTEGRATIONTESTDIR)/test_sample.cc

test_specs.o: $(INTEGRATIONTESTDIR)/test_specs.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(INTEGRATIONTESTDIR)/test_specs.cc

test_main.o: $(INTEGRATIONTESTDIR)/test_main.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(INTEGRATIONTESTDIR)/test_main.cc

all: $(OUT)

clean:
	rm -f *.o $(OUT)
