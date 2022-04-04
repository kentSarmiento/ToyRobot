CXX = g++
CXXFLAGS = -g -Wall

SRCDIR = ../../src

INCS = -I$(SRCDIR)/lib/entity \
       -I$(SRCDIR)/lib/request \
       -I$(SRCDIR)/lib/handler \
       -I$(SRCDIR)/lib/response \
       -I$(SRCDIR)/lib/value

VALUE = directions.o request_type.o
ENTITY = robot_object.o object_factory.o table.o
REQUEST = request_factory.o place_request.o
HANDLER = request_handler.o

TARGET = single.o
OUT = main

$(OUT): $(TARGET) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TARGET) $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE)

directions.o: $(SRCDIR)/lib/value/directions.cc $(SRCDIR)/lib/value/directions.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/directions.cc

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

single.o: $(SRCDIR)/apps/single.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/apps/single.cc

all: $(OUT)

clean:
	rm -f $(ENTITY) $(REQUEST) $(HANDLER) $(VALUE)

all_clean:
	rm -f $(OUT) *.o

test:
	./$(OUT)
