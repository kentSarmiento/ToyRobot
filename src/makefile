CXX = g++
CXXFLAGS = -g -Wall

SRCDIR = .

OUT = main
all: $(OUT)

include $(SRCDIR)/lib/modules.mk
include $(SRCDIR)/apps/single.mk

$(OUT): $(APP) $(LIBRARY)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(APP) $(LIBRARY)

clean:
	rm -f $(OUT) $(APP) $(LIBRARY)
