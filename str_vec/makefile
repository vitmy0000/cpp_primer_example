TARGET = main

CXX = clang++
CXXFLAGS = -std=c++11
CPP_FILES = $(shell ls *.cc)
BASE = $(basename $(CPP_FILES))
OBJS = $(addsuffix .o, $(addprefix obj/,$(BASE)))

$(TARGET):$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

obj/%.o:%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	-rm -f $(TARGET)
	-rm -f obj/*.o
