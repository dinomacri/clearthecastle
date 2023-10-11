#!/bin/bash
set -ex

CXX="g++"
CXXFLAGS="-std=c++11 -Wall -Wextra -lncurses"

TARGET="test.out"
TEST_SRCS="BossTest.cpp PlayerTest.cpp ItemTest.cpp"
SRCS="Boss.cpp Player.cpp Entity.cpp Mob.cpp Item.cpp Room.cpp"

for file in $TEST_SRCS
do
	$CXX -o $TARGET $file $SRCS $CXXFLAGS
	./$TARGET
done
