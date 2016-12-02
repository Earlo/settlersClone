CC=g++
CPPFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
#SOURCES=main.cpp src/mapGen/Map.h src/mapGen/Tile.h src/mapGen/perlin/PerlinNoise.cpp
SOURCES=main.cpp src/mapGen/Map.h src/mapGen/Tile.h src/mapGen/perlin/PerlinNoise.cpp src/Tree.h src/Settler.h src/Item.h
OBJECTS=main.o  src/mapGen/Map.o src/mapGen/Tile.o src/mapGen/perlin/PerlinNoise.o
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ $(LIBS)

.cc.o:
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: main
	./main