CC = g++
TARGET = fileIO
OBJ = 
SRC =

$(TARGET): $(OBJ) 
	$(CC) -o $(TARGET) $(OBJ) main.cpp -I.

$(OBJ): $(SRC)
	$(CC) -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
