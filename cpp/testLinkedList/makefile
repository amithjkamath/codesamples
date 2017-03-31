CC = g++
TARGET = llist
OBJ = main.o
SRC = main.cpp

$(TARGET): $(OBJ) 
	$(CC) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $(SRC) -I.

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
