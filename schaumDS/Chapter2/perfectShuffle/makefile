CC = g++
TARGET = testperfshuffle
OBJ = tperfshuffle.o perfshuffle.o
SRC = tperfshuffle.cpp perfshuffle.cpp

$(TARGET): $(OBJ) 
	$(CC) -Wall -ansi -pedantic -g -o $(TARGET) $(OBJ) -I. -lcppunit

$(OBJ): $(SRC)
	$(CC) -Wall -ansi -pedantic -g -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
