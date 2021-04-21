CC := g++
CFLAGS := -Wall -pedantic -std=c++11 -c
DBG := -g
SRC := src
INCLUDE := include
BIN := bin
LIBRARIES := -lsfml-graphics -lsfml-window -lsfml-system -llalg
EXECUTABLE := boids

OBJECTS := $(BIN)/main.o $(BIN)/Boid.o $(BIN)/BoidShape.o $(BIN)/Canvas.o $(BIN)/QuadTree.o $(BIN)/UIMath.o

$(BIN)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@ $(LIBRARIES)

$(BIN)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(DBG) -I$(INCLUDE) $< -o $@

$(BIN)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.hpp
	$(CC) $(CFLAGS) $(DBG) -I$(INCLUDE) $< -o $@

clear:
	rm $(BIN)/*