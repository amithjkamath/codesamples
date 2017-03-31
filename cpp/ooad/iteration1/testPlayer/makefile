CC = g++
#CC identifies the compiler to use. We are using g++, the C++ version of gcc.
#by the way, the # stands for a comment.
TARGET = testPlayer
#TARGET is the output file name that we expect.
OBJ = square.o die.o player.o
#OBJ includes all the names of the object files that are generated. These are then used by the linker to generate the binary.
SRC = square.cpp die.cpp player.cpp
#SRC includes all the source files needed to compile this application.

$(TARGET): $(OBJ) 
	$(CC) -Wall -ansi -pedantic -g -o $(TARGET) $(OBJ) $(TARGET).cpp -I.
#Note that the above line absolutely needs a TAB at the beginning.
#What this means is that for generating the TARGET, the OBJ files are dependencies. 
$(OBJ): $(SRC)
	$(CC) -Wall -ansi -pedantic -g -c $(SRC)
#again, what this means is that for creating each of the OBJ files, the SRC files are pre-requisites. The line above is how the source files are compiled.
# essentially,after filling out the variable values, it would look like: g++ -Wall -ansi -pedantic -g -c fraction.c
clean:
	rm -rf $(TARGET) $(OBJ) ./*~
#This is a special command to remove all the generated files. This can be called using: make clean
#also, the first command (in this case $(TARGET) : $(OBJ) ) is the default when make is called. So make without any options will do that.
