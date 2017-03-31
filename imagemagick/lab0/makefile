CC=g++
SRC=helloWorld.cpp
OUT=out

CFLAGS=`Magick++-config --cxxflags --cppflags` -O2 -Wall
LIBS=`Magick++-config --ldflags --libs`

$(OUT) : $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LIBS)

.PHONY : clean

clean:
	rm -rf ./*~ ./$(OUT) ./*.o
