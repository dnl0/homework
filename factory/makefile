TARGET := main

CXX := g++
CXXFLAGS := -std=c++14

.PHONY: all
all:
	$(CXX) $(CXXFLAGS) -DNOT main.cpp -o $(TARGET)

.PHONY: dog
dog:
	$(CXX) $(CXXFLAGS) -DDOG main.cpp -o $(TARGET)

.PHONY: cat
cat:
	$(CXX) $(CXXFLAGS) -DCAT main.cpp -o $(TARGET)

.PHONY: bird
bird:
	$(CXX) $(CXXFLAGS) -DBIRD main.cpp -o $(TARGET)
