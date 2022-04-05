INCS += -I$(SRCDIR)/lib/entity \
        -I$(SRCDIR)/lib/request \
        -I$(SRCDIR)/lib/handler \
        -I$(SRCDIR)/lib/response \
        -I$(SRCDIR)/lib/value

LIBRARY = coordinates.o \
          direction.o \
          request_type.o \
          robot_object.o \
          object_factory.o \
          table.o \
          request_factory.o \
          place_request.o \
          request_handler.o

coordinates.o: $(SRCDIR)/lib/value/coordinates.cc $(SRCDIR)/lib/value/coordinates.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/coordinates.cc

direction.o: $(SRCDIR)/lib/value/direction.cc $(SRCDIR)/lib/value/direction.h
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/lib/value/direction.cc

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
