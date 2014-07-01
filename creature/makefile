CC = g++
TARGET = creature
OBJ = creature.o point.o
SRC = creature.cpp point.cpp

$(TARGET): $(OBJ) 
	$(CC) -o $(TARGET) $(OBJ) main.cpp -I.

$(OBJ): $(SRC)
	$(CC) -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
