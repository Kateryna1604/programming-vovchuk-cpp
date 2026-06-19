.PHONY: all test clean

CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

SRC = src/entity.cpp \
      src/list.cpp \
      src/main.cpp

TESTSRC = test/test.cpp \
          src/entity.cpp \
          src/list.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o main.bin

test:
	$(CXX) $(CXXFLAGS) $(TESTSRC) \
	-lgtest -lgtest_main -pthread \
	-o test.bin

clean:
	rm -f main.bin test.bin
