CC = g++
TARGET = shrlib
LIB = code
LIBNAME = lib$(LIB)
OBJ = $(LIBNAME).so
SRC = libcode.cpp

$(TARGET): $(OBJ) 
	$(CC) -o $(TARGET) -I. main.cpp -L. -l$(LIB)

$(OBJ): $(SRC)
	$(CC) -c $(LIBNAME).cpp -o $(LIBNAME).o
	# -c creates an object file, without any 'main' entry point.
	$(CC) -shared -fPIC -o $(OBJ) $(LIBNAME).o 
# fPIC is position independent code, shared creates a shared library.

clean:
	rm -rf $(TARGET) $(OBJ) ./*~
