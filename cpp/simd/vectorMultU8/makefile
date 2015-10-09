CC = g++
TARGET = vectorMultU8
OBJ = vectorMultU8.o
SRC = vectorMultU8.cpp

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c -msse4 $(SRC) -I.

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
