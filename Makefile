# Makefile

CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra -lncurses
DEBUGFLAG = -DDEBUG

TARGET = run.out

MAIN_SRC = clearthecastle.cpp
SRCS = Boss.cpp Player.cpp Entity.cpp Mob.cpp Item.cpp Room.cpp Logger.cpp

TEST_SCRIPT = test.sh

# Cleanup files

CLEAN_FILES = *.gch

# Build, test, run
.PHONY: all
all:

	$(CXX) -o $(TARGET) $(MAIN_SRC) $(SRCS) $(CXXFLAGS)

	./$(TARGET)

# Build, test, run (DEBUG)
.PHONY: debug
debug: test
	$(CXX) -o $(TARGET) $(MAIN_SRC) $(SRCS) $(CXXFLAGS) $(DEBUGFLAG)

	./$(TARGET)

# Build and run (no test)
.PHONY: notest
notest:
	$(CXX) -o $(TARGET) $(MAIN_SRC) $(SRCS) $(CXXFLAGS)

	./$(TARGET)

# Test
.PHONY: test
test: 
	/bin/bash $(TEST_SCRIPT) && echo "Testing Complete\n"

# Clean rule
.PHONY: clean
clean:

	rm -f $(TARGET) $(CLEAN_FILES)
