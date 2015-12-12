#!/usr/bin/make
all: clean debug
build:
	mkdir -p bin
	g++-5 --std=c++14 -Wall -Wextra -pedantic -O2 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o bin/gromenia src/*.cpp
debug:
	mkdir -p bin
	g++-5 --std=c++14 -Wall -Wextra -pedantic -ggdb -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o bin/gromenia src/*.cpp
clean:
	rm -rf bin
