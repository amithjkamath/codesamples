CC = g++
TARGET = testVector
OBJ = 
SRC = 

$(TARGET): $(OBJ) 
	$(CC) -Wall -ansi -pedantic -g -o $(TARGET) $(OBJ) testVector.cpp -I.

$(OBJ): $(SRC)
	$(CC) -Wall -ansi -pedantic -g -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
