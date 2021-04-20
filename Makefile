CC := g++
CFLAGS := -Wall -pedantic -std=c++11
DBG := -g
SRC := src
INCLUDE := include
BIN := bin
LIBRARIES := -lsfml-graphics -lsfml-window -lsfml-system -llalg
EXECUTABLE := boids


$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CC) $(CFLAGS) $(DBG) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clear:
	rm $(BIN)/*