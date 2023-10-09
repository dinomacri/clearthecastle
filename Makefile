# Makefile

CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra -lncurses

TARGET = run.out

SRCS = clearthecastle.cpp Boss.cpp Player.cpp Entity.cpp Mob.cpp Item.cpp

# Cleanup files

CLEAN_FILES = *.gch

# Build and run

.PHONY: all

all:

	$(CXX) -o $(TARGET) $(SRCS) $(CXXFLAGS)

	./$(TARGET)

# Clean rule

.PHONY: clean

clean:

	rm -f $(TARGET) $(CLEAN_FILES)
