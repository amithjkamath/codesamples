CC = g++
TARGET = testsdcalc
OBJ = tsdcalc.o sdcalc.o
SRC = tsdcalc.cpp sdcalc.cpp

$(TARGET): $(OBJ) 
	$(CC) -Wall -ansi -pedantic -g -o $(TARGET) $(OBJ) -I. -lcppunit

$(OBJ): $(SRC)
	$(CC) -Wall -ansi -pedantic -g -c $(SRC)

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
