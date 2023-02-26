TARGET := main.o

CXX := g++
CXXFLAGS := -std=c++14

SOURCES := $(wildcard *.cpp)

.PHONY: all
all: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)
