CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = src/entity.cpp src/list.cpp

MAIN = src/main.cpp
TEST = test/test.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) $(MAIN) -o main.bin

run_tests:
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST) -lgtest -lgtest_main -pthread -o test.bin

clean:
	rm -f main.bin test.bin
