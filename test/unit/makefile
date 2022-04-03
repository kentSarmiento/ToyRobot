CXX = g++
CXXFLAGS = -g -Wall

SRCDIR = ../../src
TESTDIR = ../../test
UNITTESTDIR= $(TESTDIR)/unit

INCS = -I$(TESTDIR) \
       -I$(TESTDIR)/lib/entity \
       -I$(SRCDIR)/lib/entity \
       -I$(SRCDIR)/lib/value

ENTITY = test_base_object.o
TARGET = test_main.o
OUT = main

$(OUT): $(TARGET) $(ENTITY)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TARGET) $(ENTITY)

test_base_object.o: $(UNITTESTDIR)/lib/entity/test_base_object.cc $(UNITTESTDIR)/lib/entity/test_base_object.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/lib/entity/test_base_object.cc

test_main.o: $(UNITTESTDIR)/test_main.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(UNITTESTDIR)/test_main.cc

all: $(OUT)

clean:
	rm -f *.o $(OUT)
