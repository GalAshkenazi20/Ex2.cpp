CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
VALFLAGS = --leak-check=full --show-leak-kinds=all --error-exitcode=99 --track-origins=yes --verbose --log-file=valgrind-out.txt

TARGET = main
TEST_EXEC = test_exec

SOURCES = main.cpp SquareMat.cpp
HEADERS = SquareMat.hpp
TEST_SRC = tests.cpp SquareMat.cpp

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

test: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_SRC)

run-tests: test
	@echo "🔍 Running tests..."
	@./$(TEST_EXEC) || { echo '❌ Tests failed!'; exit 1; }
	@echo "✅ All tests passed."

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind $(VALFLAGS) ./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_EXEC) *.txt
