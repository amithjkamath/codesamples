CC=g++
SRC=lab0.cpp
OUT=out

CFLAGS=`pkg-config --cflags opencv` -Wall
LIBS=`pkg-config --libs opencv`

$(OUT) : $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LIBS)

.PHONY : clean

clean:
	rm -rf ./*~ ./$(OUT) ./*.o
