APP = single.o

single.o: $(SRCDIR)/apps/single.cc
	$(CXX) $(CXXFLAGS) $(INCS) -c $(SRCDIR)/apps/single.cc