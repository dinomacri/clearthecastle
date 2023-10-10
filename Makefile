# Makefile

CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra -lncurses

TARGET = run.out

MAIN_SRC = clearthecastle.cpp
SRCS = Boss.cpp Player.cpp Entity.cpp Mob.cpp Item.cpp

TEST_SCRIPT = test.sh

# Cleanup files

CLEAN_FILES = *.gch

# Build, test, run
.PHONY: all
all: test

	$(CXX) -o $(TARGET) $(MAIN_SRC) $(SRCS) $(CXXFLAGS)

	./$(TARGET)

# Build and run (no test)
.PHONY: notest
notest:
	$(CXX) -o $(TARGET) $(MAIN_SRC) $(SRCS) $(CXXFLAGS)

# Test
.PHONY: test
test: 
	/bin/bash $(TEST_SCRIPT)

# Clean rule
.PHONY: clean
clean:

	rm -f $(TARGET) $(CLEAN_FILES)
