CC=g++
CPPFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
#SOURCES=main.cpp src/mapGen/Map.h src/mapGen/Tile.h src/mapGen/perlin/PerlinNoise.cpp
#SOURCES=main.cpp src/mapGen/Map.h src/mapGen/Tile.h src/mapGen/perlin/PerlinNoise.cpp src/Resource.h src/Settler.h src/Item.h 
#SOURCES=main.cpp src/mapGen/Map.h src/mapGen/Tile.h src/mapGen/perlin/PerlinNoise.cpp src/Settler.cpp 
#SOURCES=*.cpp *.h src/*.h src/*.cpp src/mapGen/*.cpp src/mapGen/*.h src/mapGen/perlin/*.cpp
SOURCES=*.cpp *.h src/*.h src/*.cpp src/mapGen/*.cpp src/mapGen/*.h src/logic/*.h src/mapGen/perlin/*.cpp src/Settler.cpp

#OBJECTS=main.o src/Settler.o src/mapGen/Map.o src/mapGen/Tile.o src/mapGen/perlin/PerlinNoise.o
OBJECTS=main.o src/mapGen/Map.o src/mapGen/Tile.o src/mapGen/perlin/PerlinNoise.o

#OBJECTS= *.o  src/*.o src/mapGen/*.o src/mapGen/perlin/*.o


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