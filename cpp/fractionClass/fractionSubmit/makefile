CC = g++
TARGET = fractionTest
OBJ = fraction.o testCode.o
SRC = fraction.cpp testCode.cpp

$(TARGET): $(OBJ) 
	$(CC) -Wall -ansi -pedantic -g -o $(TARGET) $(OBJ) main.cpp -I.

$(OBJ): $(SRC)
	$(CC) -Wall -ansi -pedantic -g -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
