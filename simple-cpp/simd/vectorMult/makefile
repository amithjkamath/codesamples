CC = g++
TARGET = vectorMult
OBJ = vectorMult.o
SRC = vectorMult.cpp

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c -msse4 $(SRC) -I.

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
