CC=g++
CFLAGS=-I.
DEPS = 
OBJ = sumTwoNumbers.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sumTwoNumbers: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~ ./sumTwoNumbers