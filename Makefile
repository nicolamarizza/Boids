CC := g++
CFLAGS := -Wall -pedantic -std=c++11
DBG := -g
SRC := src
INCLUDE := include
BIN := bin
LIBRARIES := -llalg -lsfml-system -lsfml-window -lsfml-graphics
EXECUTABLE := boids


$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CC) $(CFLAGS) $(DBG) -I$(INCLUDE) -o $@ $(LIBRARIES)

clear:
	rm $(BIN)/*