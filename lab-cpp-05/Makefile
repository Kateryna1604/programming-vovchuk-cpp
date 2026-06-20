.PHONY: all test clean

CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

all:
	$(CXX)	$(CXXFLAGS) src/main.cpp -o main.bin

test:
	$(CXX)	$(CXXFLAGS) test/test.cpp \
	-lgtest -lgtest_main -pthread \
	-o test.bin

clean:
	rm -f main.bin test.bin
