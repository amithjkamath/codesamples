CC = g++
TARGET = testtransmatrix
OBJ = ttransmatrix.o transmatrix.o
SRC = ttransmatrix.cpp transmatrix.cpp

$(TARGET): $(OBJ) 
	$(CC) -Wall -ansi -g -o $(TARGET) $(OBJ) -I. -lcppunit

$(OBJ): $(SRC)
	$(CC) -Wall -ansi -g -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
