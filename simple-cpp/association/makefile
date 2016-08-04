CC = g++
TARGET = association
OBJ = person.o car.o
SRC = person.cpp car.cpp

$(TARGET): $(OBJ) 
	$(CC) -o $(TARGET) $(OBJ) main.cpp -I.

$(OBJ): $(SRC)
	$(CC) -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
