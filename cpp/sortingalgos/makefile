CC = g++
TARGET = bubbleSortTest
OBJ = bubbleSort.o
SRC = bubbleSort.cpp

$(TARGET): $(OBJ)
	$(CC) -Wall -ansi -pedantic -g -o $(TARGET) $(OBJ) -I.

$(OBJ): $(SRC)
	$(CC) -Wall -ansi -pedantic -g -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
