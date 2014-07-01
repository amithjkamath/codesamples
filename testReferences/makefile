CC = g++
TARGET = testThis
OBJ = testRef.o
SRC = testRef.cpp

$(TARGET): $(OBJ) 
	$(CC) -o $(TARGET) $(OBJ) main.cpp -I.

$(OBJ): $(SRC)
	$(CC) -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
