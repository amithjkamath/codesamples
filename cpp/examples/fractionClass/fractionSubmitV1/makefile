CC = g++
TARGET = fractionTest
OBJ = fraction.o testCode.o
SRC = fraction.cpp testCode.cpp

$(TARGET): $(OBJ) 
	$(CC) -o $(TARGET) $(OBJ) main.cpp -I.

$(OBJ): $(SRC)
	$(CC) -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
