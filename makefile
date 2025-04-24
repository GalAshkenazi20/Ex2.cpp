CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

TARGET = main
SOURCES = main.cpp SquareMat.cpp
HEADERS = SquareMat.hpp

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)