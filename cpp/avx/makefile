CC = g++
TARGET = testAVX
OBJ = testavx.o
SRC = testavx.cpp

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c -mavx $(SRC) -I.

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
